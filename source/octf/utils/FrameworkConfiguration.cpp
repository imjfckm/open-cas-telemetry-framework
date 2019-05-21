/*
 * Copyright(c) 2012-2018 Intel Corporation
 * SPDX-License-Identifier: BSD-3-Clause-Clear
 */

#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sstream>
#include <octf/utils/Exception.h>
#include <octf/utils/FrameworkConfiguration.h>
#include <octf/utils/ProtobufReaderWriter.h>

namespace octf {

#ifndef OCTF_CONFIG_FILE
#error "OCTF_CONFIG_FILE not defined"
#endif

#define STR_VALUE(val) #val
#define TOSTR(name) STR_VALUE(name)

const std::string &octf::FrameworkConfiguration::getVersion() const {
    static const std::string label = TOSTR(OCTF_VERSION_LABEL);

    if (label != "") {
        static const std::string version =
                std::string(TOSTR(OCTF_VERSION)) + " (" +
                std::string(TOSTR(OCTF_VERSION_LABEL)) + ")";

        return version;
    } else {
        static const std::string version = TOSTR(OCTF_VERSION);

        return version;
    }
}

const std::string &FrameworkConfiguration::getNodeSettingsDir() const {
    return m_config.paths().settings();
}

std::string FrameworkConfiguration::getNodeSettingsFilePath(
        const NodePath &path) const {
    return getNodeSettingsDir() + "/" + getNodePathBasename(path);
}

const std::string &FrameworkConfiguration::getUnixSocketDir() const {
    return m_config.paths().unixsocket();
}

std::string FrameworkConfiguration::getUnixSocketFilePath(
        const NodeId &id) const {
    return getUnixSocketDir() + "/" + id.getId();
}

const std::string &FrameworkConfiguration::getTraceDir() const {
    return m_config.paths().trace();
}

std::string FrameworkConfiguration::getNodeTraceDirectoryPath(
        const NodePath &path) const {
    return getTraceDir() + "/" + getNodePathBasename(path);
}

std::string FrameworkConfiguration::getNodePathBasename(
        const NodePath &path) const {
    if (!path.size()) {
        throw Exception("Empty path");
    }

    std::string basename;

    // Get root node and generate beginning of basename
    auto iter = path.begin();
    basename = iter->getId();
    iter++;

    // Then continue creating file name consisted of children nodes items
    for (; iter != path.end(); iter++) {
        basename += ":";
        basename += iter->getId();
    }

    return basename;
}

FrameworkConfiguration::FrameworkConfiguration() {
    ProtobufReaderWriter rw(OCTF_CONFIG_FILE);

    if (false == rw.read(m_config)) {
        throw Exception("Cannot read framework configuration");
    }
}

const FrameworkConfiguration &getFrameworkConfiguration() {
    static FrameworkConfiguration instance;
    return instance;
}

}  // namespace octf
