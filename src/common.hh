/*!
 *
﻿ * Copyright (C) 2015 Technical University of Liberec.  All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License version 3 as published by the
 * Free Software Foundation. (http://www.gnu.org/licenses/gpl-3.0.en.html)
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 *
 * @file    bounding_box.hh
 * @brief
 */

#ifndef COMMON_HH_
#define COMMON_HH_

#if DEBUG
#define ASSERT( COND, MESSAGE)
    if (! (COND)) {
        cout << MESSAGE;
    }
#else
#define ASSERT(COND, MESSAGE)
#endif

#endif
