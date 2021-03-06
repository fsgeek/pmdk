/*
 * Copyright 2014-2019, Intel Corporation
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in
 *       the documentation and/or other materials provided with the
 *       distribution.
 *
 *     * Neither the name of the copyright holder nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <errno.h>
#include <sys/stat.h>

#include "libpmem2.h"
#include "out.h"
#include "pmem2_utils.h"

#ifdef _WIN32
#define S_ISREG(m)	(((m) & S_IFMT) == S_IFREG)
#define S_ISDIR(m)	(((m) & S_IFMT) == S_IFDIR)
#endif

int
pmem2_get_type_from_stat(const os_stat_t *st, enum pmem2_file_type *type)
{
	if (S_ISREG(st->st_mode)) {
		*type = PMEM2_FTYPE_REG;
		return 0;
	}

	if (S_ISDIR(st->st_mode)) {
		*type = PMEM2_FTYPE_DIR;
		return 0;
	}

	ERR("file type 0%o not supported", st->st_mode & S_IFMT);
	return PMEM2_E_INVALID_FILE_TYPE;
}

/*
 * pmem2_device_dax_size_from_stat -- (internal) checks the size of a given
 * dax device from given stat structure
 */
int
pmem2_device_dax_size_from_stat(const os_stat_t *st, size_t *size)
{
	const char *err =
		"BUG: pmem2_device_dax_size_from_stat should never be called on this OS";
	ERR("%s", err);
	ASSERTinfo(0, err);
	return PMEM2_E_NOSUPP;
}

/*
 * pmem2_device_dax_alignment_from_stat -- checks the alignment of a given
 * dax device from given stat structure
 */
int
pmem2_device_dax_alignment_from_stat(const os_stat_t *st, size_t *alignment)
{
	const char *err =
		"BUG: pmem2_device_dax_alignment_from_stat should never be called on this OS";
	ERR("%s", err);
	ASSERTinfo(0, err);
	return PMEM2_E_NOSUPP;
}
