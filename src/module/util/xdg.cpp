/*
 * Copyright (c) 2021. Uniontech Software Ltd. All rights reserved.
 *
 * Author:     Iceyer <me@iceyer.net>
 *
 * Maintainer: Iceyer <me@iceyer.net>
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <QDir>
#include <QMap>
#include <QStandardPaths>

namespace linglong {
namespace util {

QDir userRuntimeDir()
{
    return QDir(QStandardPaths::standardLocations(QStandardPaths::RuntimeLocation).value(0));
}

//! https://specifications.freedesktop.org/desktop-entry-spec/desktop-entry-spec-latest.html#exec-variables
//! \param exec
//! \return
//! TODO: should compatibility with：
//!     env a=b c
QStringList parseExec(const QString &exec)
{
    // const auto Backtick = '`';
    const auto Quote = '"';
    const auto Space = ' ';
    const auto BackSlash = '\\';

    QStringList args;
    bool argBegin = false;
    bool inQuote = false;
    QString arg;
    for (int i = 0; i < exec.length(); ++i) {
        switch (exec.at(i).toLatin1()) {
        case BackSlash:
            if (inQuote) {
                inQuote = !inQuote;
                arg.push_back(exec.at(i));
                break;
            }

            argBegin = true;
            inQuote = true;
            break;
        case Quote:
            if (inQuote) {
                inQuote = !inQuote;
                arg.push_back(exec.at(i));
                break;
            }
            break;
        case Space:
            if (inQuote) {
                inQuote = !inQuote;
                arg.push_back(exec.at(i));
                break;
            }

            // terminal arg with space
            if (!argBegin) {
            } else {
                args.push_back(arg);
                arg = "";
            }
            argBegin = false;
            break;
        default:
            argBegin = true;
            arg.push_back(exec.at(i));
            break;
        }
    }
    if (!arg.isEmpty()) {
        args.push_back(arg);
    }
    return args;
}

QPair<QString, QString> parseEnvKeyValue(QString env, const QString &sep)
{
    QRegExp exp("(\\$\\{.*\\})");
    exp.setMinimal(true);
    exp.indexIn(env);

    for (auto const &envReplace : exp.capturedTexts()) {
        auto envKey = QString(envReplace).replace("$", "").replace("{", "").replace("}", "");
        auto envValue = qEnvironmentVariable(envKey.toStdString().c_str());
        env.replace(envReplace, envValue);
    }

    auto sepPos = env.indexOf(sep);

    if (sepPos < 0) {
        return {env, ""};
    }

    return {env.left(sepPos), env.right(env.length() - sepPos - 1)};
}

} // namespace util
} // namespace linglong