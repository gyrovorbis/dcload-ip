/*
 * This file is part of the dcload Dreamcast ethernet loader
 *
 * Copyright (C) 2001 Andrew Kieschnick <andrewk@austin.rr.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */

#ifndef __SYSCALLS_H__
#define __SYSCALLS_H__

void set_mappath(char *path);

int dc_fstat(unsigned char *buffer);
int dc_write(unsigned char * buffer);
int dc_read(unsigned char * buffer);
int dc_open(unsigned char * buffer);
int dc_close(unsigned char * buffer);
int dc_creat(unsigned char * buffer);
int dc_link(unsigned char * buffer);
int dc_unlink(unsigned char * buffer);
int dc_chdir(unsigned char * buffer);
int dc_chmod(unsigned char * buffer);
int dc_lseek(unsigned char * buffer);
int dc_time(unsigned char * buffer);
int dc_stat(unsigned char * buffer);
int dc_utime(unsigned char * buffer);

int dc_opendir(unsigned char * buffer);
int dc_readdir(unsigned char * buffer);
int dc_closedir(unsigned char * buffer);
int dc_rewinddir(unsigned char * buffer);

int dc_cdfs_redir_read_sectors(int isofd, unsigned char * buffer);

int dc_gdbpacket(unsigned char * buffer);

#define CMD_EXIT     "DC00"
#define CMD_FSTAT    "DC01"
#define CMD_WRITE_OLD    "DD02"
#define CMD_WRITE    "DC02"
#define CMD_READ     "DC03"
#define CMD_OPEN     "DC04"
#define CMD_CLOSE    "DC05"
#define CMD_CREAT    "DC06"
#define CMD_LINK     "DC07"
#define CMD_UNLINK   "DC08"
#define CMD_CHDIR    "DC09"
#define CMD_CHMOD    "DC10"
#define CMD_LSEEK    "DC11"
#define CMD_TIME     "DC12"
#define CMD_STAT     "DC13"
#define CMD_UTIME    "DC14"
#define CMD_BAD      "DC15"
#define CMD_OPENDIR  "DC16"
#define CMD_CLOSEDIR "DC17"
#define CMD_READDIR  "DC18"
#define CMD_CDFSREAD "DC19"
#define CMD_GDBPACKET "DC20"
#define CMD_REWINDDIR "DC21"

// Special definition for exception handler data
#define CMD_EXCEPTION "EXPT"

struct _command_3int_t {
	unsigned char id[4];
	unsigned int value0;
	unsigned int value1;
	unsigned int value2;
} __attribute__ ((__packed__));

struct _command_2int_string_t {
	unsigned char id[4];
	unsigned int value0;
	unsigned int value1;
	char string[1];
} __attribute__ ((__packed__));

struct _command_int_t {
	unsigned char id[4];
	unsigned int value0;
} __attribute__ ((__packed__));

struct _command_int_string_t {
	unsigned char id[4];
	unsigned int value0;
	char string[1];
} __attribute__ ((__packed__));

struct _command_string_t {
	unsigned char id[4];
	char string[1];
} __attribute__ ((__packed__));

struct _command_3int_string_t {
	unsigned char id[4];
	unsigned int value0;
	unsigned int value1;
	unsigned int value2;
	char string[1];
} __attribute__ ((__packed__));

typedef struct _command_3int_t command_3int_t;
typedef struct _command_2int_string_t command_2int_string_t;
typedef struct _command_int_t command_int_t;
typedef struct _command_int_string_t command_int_string_t;
typedef struct _command_string_t command_string_t;
typedef struct _command_3int_string_t command_3int_string_t;

/* fstat    fd, addr, size
 * write    fd, addr, size
 * read     fd, addr, size
 * open     flags, mode, string
 * close    fd
 * creat    mode, string
 * link     string1+string2
 * unlink   string
 * chdir    string
 * cdmod    mode, string
 * lseek    fd, offset, whence
 * time     -
 * stat     addr, size, string
 * utime    foo, actime, modtime, string
 * opendir  string
 * closedir dir
 * readdir  dir, addr, size
 * cdfsread sector, addr, size
 * gdb_packet count, size, string
 */

#endif
