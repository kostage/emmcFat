/*-----------------------------------------------------------------------*/
/* Low level disk I/O module skeleton for FatFs     (C)ChaN, 2014        */
/*-----------------------------------------------------------------------*/
/* If a working storage control module is available, it should be        */
/* attached to the FatFs via a glue function rather than modifying it.   */
/* This is an example of glue functions to attach various exsisting      */
/* storage control modules to the FatFs module with a defined API.       */
/*-----------------------------------------------------------------------*/

#include "diskio.h"
#include "hw_types.h"
#include "syl_mmcsd_proto.h"
#include "syl_hs_mmcsdlib.h"
#include "ff.h"
#include "uartStdio.h"


typedef struct _fatDevice
{
    /* Pointer to underlying device/controller */
    void *dev;

    /* File system pointer */
    FATFS *fs;

	/* state */
	unsigned int initDone;

}fatDevice;


#define DRIVE_NUM_MMCSD     0
#define DRIVE_NUM_MAX      2


fatDevice fat_devices[DRIVE_NUM_MAX];

/*-----------------------------------------------------------------------*/
/* Get Drive Status                                                      */
/*-----------------------------------------------------------------------*/

DSTATUS disk_status (
	BYTE pdrv		/* Physical drive nmuber to identify the drive */
)
{
	return 0;
}



/*-----------------------------------------------------------------------*/
/* Inidialize a Drive                                                    */
/*-----------------------------------------------------------------------*/

DSTATUS disk_initialize (
	BYTE pdrv				/* Physical drive nmuber to identify the drive */
)
{
	unsigned int status;

    if (DRIVE_NUM_MAX <= pdrv)
    {
        return STA_NODISK;
    }

    if ((DRIVE_NUM_MMCSD == pdrv) && (fat_devices[pdrv].initDone != 1))
    {
        mmcsdCardInfo *card = (mmcsdCardInfo *) fat_devices[pdrv].dev;

        /* SD Card init */
        status = MMCSDCardInit(card->ctrl);

        if (status == 0)
        {
            UARTPuts("\r\nCard Init Failed \r\n", -1);

            return STA_NOINIT;
        }
        else
        {
            /* Set bus width */
            if (card->cardType == MMCSD_CARD_MMC)
            	card->busWidth = SD_BUS_WIDTH_8BIT;
            else
            	card->busWidth = SD_BUS_WIDTH_4BIT;

            //ф-и сами различают тип карты
           MMCSDBusWidthSet(card->ctrl);
                /* Transfer speed */
           MMCSDTranSpeedSet(card->ctrl);

        }

		fat_devices[pdrv].initDone = 1;
    }

    return 0;
}



/*-----------------------------------------------------------------------*/
/* Read Sector(s)                                                        */
/*-----------------------------------------------------------------------*/

DRESULT disk_read (
	BYTE pdrv,		/* Physical drive nmuber to identify the drive */
	BYTE *buff,		/* Data buffer to store read data */
	DWORD sector,	/* Sector address in LBA */
	UINT count		/* Number of sectors to read */
)
{
	if (pdrv == DRIVE_NUM_MMCSD)
	{
		mmcsdCardInfo *card = fat_devices[pdrv].dev;

    	/* READ BLOCK */
		if (MMCSDReadCmdSend(card->ctrl, buff, sector, count) == 1)
		{
        	return RES_OK;
		}
    }

    return RES_ERROR;
}



/*-----------------------------------------------------------------------*/
/* Write Sector(s)                                                       */
/*-----------------------------------------------------------------------*/

#if _USE_WRITE
DRESULT disk_write (
	BYTE pdrv,			/* Physical drive nmuber to identify the drive */
	const BYTE *buff,	/* Data to be written */
	DWORD sector,		/* Sector address in LBA */
	UINT count			/* Number of sectors to write */
)
{
	if (pdrv == DRIVE_NUM_MMCSD)
	{
		mmcsdCardInfo *card = fat_devices[pdrv].dev;
    	/* WRITE BLOCK */
	    if(MMCSDWriteCmdSend(card->ctrl,(BYTE*) buff, sector, count) == 1)
		{
        	return RES_OK;
		}
	}

    return RES_ERROR;
}
#endif


/*-----------------------------------------------------------------------*/
/* Miscellaneous Functions                                               */
/*-----------------------------------------------------------------------*/

#if _USE_IOCTL
DRESULT disk_ioctl (
	BYTE pdrv,		/* Physical drive nmuber (0..) */
	BYTE cmd,		/* Control code */
	void *buff		/* Buffer to send/receive control data */
)
{
	DRESULT res = RES_ERROR;
	if (pdrv == DRIVE_NUM_MMCSD)
	{
		mmcsdCardInfo *card = fat_devices[pdrv].dev;
    	switch (cmd)
    	{
    		case GET_SECTOR_COUNT:
				*(unsigned int*)(buff) = card->nBlks;
				res = RES_OK;
			break;

    		case GET_BLOCK_SIZE:
    			*(unsigned int*)(buff) = 1;//хз
    			res = RES_OK;
    		break;

    		case CTRL_SYNC:
    			res = RES_OK;

    		default:
    		break;
    	}
	}

    return res;
}
#endif
