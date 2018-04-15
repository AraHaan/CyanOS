/*
 * System Memory pages include file.
 */
#ifndef KERNEL_PAGES_H
#define KERNEL_PAGES_H
typedef struct _PAGEDATA
{
  void[] data;
} PAGEDATA;

typedef struct _PAGEDATALIST
{
  PAGEDATA[] page;
} PAGEDATALIST;

/// summary:
/// Makes system memory pages.
/// returns:
/// System page list of the
/// calling process.
KEXTERN PAGEDATALIST MakePages(void[] data);
#endif
