/*
 * Copyright (c) 2018 Particle Industries, Inc.  All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <cstddef>

namespace particle {

// Base abstract class for an input stream
class InputStream {
public:
    virtual ~InputStream() = default;

    virtual int read(char* data, size_t size) = 0;
};

// Base abstract class for an output stream
class OutputStream {
public:
    virtual ~OutputStream() = default;

    virtual int write(const char* data, size_t size) = 0;
};

// Base abstract class for a bidirectional stream
class Stream:
        virtual public InputStream,
        virtual public OutputStream {
public:
    enum EventFlag {
        READABLE = 0x01,
        WRITABLE = 0x02
    };

    virtual int waitEvent(unsigned flags, unsigned timeout = 0) = 0;
};

} // particle
