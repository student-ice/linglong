/*
 * SPDX-FileCopyrightText: 2022 UnionTech Software Technology Co., Ltd.
 *
 * SPDX-License-Identifier: LGPL-3.0-or-later
 */

#include "repo.h"

#include <QDir>
#include <QString>

#include "module/package/info.h"
#include "module/util/sysinfo.h"

#include "ostree_repo.h"
#include "repo_client.h"

namespace linglong {
namespace repo {

void registerAllMetaType()
{
    qJsonRegister<ParamStringMap>();
    qJsonRegister<linglong::repo::InfoResponse>();
    qJsonRegister<linglong::repo::UploadResponseData>();
    qJsonRegister<linglong::repo::AuthResponse>();
    qJsonRegister<linglong::repo::AuthResponseData>();
    qJsonRegister<linglong::repo::RevPair>();
    qJsonRegister<linglong::repo::UploadRequest>();
    qJsonRegister<linglong::repo::UploadTaskRequest>();
    qJsonRegister<linglong::repo::UploadTaskResponse>();
}

} // namespace repo
} // namespace linglong
