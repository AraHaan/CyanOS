/*
 * pages.c
 * This file implements memory pages
 * which is always 4096 bytes long.
 */
#define WITH_KERNEL
#include "../../include/Cyanyde.h"

PAGEDATALIST MakePages(void[] data)
{
  // make pages by every 4096
  // bytes in the array.
  int page_num = 0;
  PAGEDATALIST pagelist;
  for (int page = 0; page < sizeof(data); page + 4096)
  {
    PAGEDATA pdata;
    for (int i = 0; i < page; i++)
    {
      pdata.data[i] = data[i];
      if (i == page)
      {
        page_num++;
        pagelist.page[page_num] = pdata;
      }
    }
  }
  return pagelist;
}
