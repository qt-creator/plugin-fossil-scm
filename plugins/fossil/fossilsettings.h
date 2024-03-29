/****************************************************************************
**
** Copyright (c) 2018 Artur Shepilko
** Contact: https://www.qt.io/licensing/
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 as published by the Free Software
** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
****************************************************************************/

#pragma once

#include <coreplugin/dialogs/ioptionspage.h>
#include <vcsbase/vcsbaseclientsettings.h>

namespace Fossil {
namespace Internal {

class FossilSettings : public VcsBase::VcsBaseSettings
{
public:
    Utils::StringAspect defaultRepoPath;
    Utils::StringAspect sslIdentityFile;
    Utils::BoolAspect diffIgnoreAllWhiteSpace;
    Utils::BoolAspect diffStripTrailingCR;
    Utils::BoolAspect annotateShowCommitters;
    Utils::BoolAspect annotateListVersions;
    Utils::IntegerAspect timelineWidth;
    Utils::StringAspect timelineLineageFilter;
    Utils::BoolAspect timelineVerbose;
    Utils::StringAspect timelineItemType;
    Utils::BoolAspect disableAutosync;

    FossilSettings();
};

struct RepositorySettings
{
    enum AutosyncMode {AutosyncOff, AutosyncOn, AutosyncPullOnly};

    QString user;
    QString sslIdentityFile;
    AutosyncMode autosync = AutosyncOn;
};

inline bool operator==(const RepositorySettings &lh, const RepositorySettings &rh)
{
    return (lh.user == rh.user &&
            lh.sslIdentityFile == rh.sslIdentityFile &&
            lh.autosync == rh.autosync);
}

class OptionsPage : public Core::IOptionsPage
{
public:
    OptionsPage(const std::function<void()> &onApply, FossilSettings *settings);
};

} // namespace Internal
} // namespace Fossil
