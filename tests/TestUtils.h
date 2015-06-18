/*
 *  CLRadeonExtender - Unofficial OpenCL Radeon Extensions Library
 *  Copyright (C) 2014-2015 Mateusz Szpakowski
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef __CLRXTEST_TESTUTILS_H__
#define __CLRXTEST_TESTUTILS_H__

#include <CLRX/Config.h>
#include <iostream>
#include <sstream>
#include <cstring>
#include <initializer_list>
#include <CLRX/utils/Utilities.h>

using namespace CLRX;

static void assertTrue(const std::string& testName, const std::string& caseName,
           bool value)
{
    if (!value)
    {
        std::ostringstream oss;
        oss << "Failed " << testName << ":" << caseName;
        oss.flush();
        throw Exception(oss.str());
    }
}


template<typename T>
static void assertValue(const std::string& testName, const std::string& caseName,
            const T& expected, const T& result)
{
    if (expected != result)
    {
        std::ostringstream oss;
        oss << "Failed " << testName << ":" << caseName << "\n" <<
            expected << "!=" << result;
        oss.flush();
        throw Exception(oss.str());
    }
}

static void assertString(const std::string& testName, const std::string& caseName,
             const char* expected, const char* result)
{
    if (::strcmp(expected, result) != 0)
    {
        std::ostringstream oss;
        oss << "Failed " << testName << ":" << caseName << "\n" <<
            "\"" << expected << "\"!=\"" << result << "\"";
        oss.flush();
        throw Exception(oss.str());
    }
}

template<typename T>
static void assertArray(const std::string& testName, const std::string& caseName,
            const std::initializer_list<T>& expected, size_t resultSize, const T* result)
{
    if (expected.size() != resultSize)
    {
        std::ostringstream oss;
        oss << "Failed " << testName << ":" << caseName << " \n" <<
            "Size of Array: " << expected.size() << "!=" << resultSize;
        oss.flush();
        throw Exception(oss.str());
    }
    auto it = expected.begin();
    for (size_t i = 0; i < resultSize ; i++, ++it)
        if (*it != result[i])
        {
            std::ostringstream oss;
            oss << "Failed " << testName << ":" << caseName << " \n" <<
                "Elem #" << i << ": " << *it << "!=" << result[i];
            oss.flush();
            throw Exception(oss.str());
        }
}

static void assertStrArray(const std::string& testName, const std::string& caseName,
            const std::initializer_list<const char*>& expected,
            size_t resultSize, const char** result)
{
    if (expected.size() != resultSize)
    {
        std::ostringstream oss;
        oss << "Failed " << testName << ":" << caseName << " \n" <<
            "Size of Array: " << expected.size() << "!=" << resultSize;
        oss.flush();
        throw Exception(oss.str());
    }
    auto it = expected.begin();
    for (size_t i = 0; i < resultSize ; i++, ++it)
        if (::strcmp(*it, result[i]) != 0)
        {
            std::ostringstream oss;
            oss << "Failed " << testName << ":" << caseName << " \n" <<
                "Elem #" << i << ": " << *it << "!=" << result[i];
            oss.flush();
            throw Exception(oss.str());
        }
}


template<typename Call, typename... T>
static int callTest(Call* call, T ...args)
{
    try
    { call(args...); }
    catch(const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
        return 1;
    }
    return 0;
}

#endif