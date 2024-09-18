/******************************************************************************
 *
 * Project:  KML Translator
 * Purpose:  Implements OGRLIBKMLDriver
 * Author:   Brian Case, rush at winkey dot org
 *
 ******************************************************************************
 * Copyright (c) 2010, Brian Case
 * Copyright (c) 2014, Even Rouault <even dot rouault at spatialys.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *****************************************************************************/

#ifndef OGRLIBKMLFIELDCONFIG_H_INCLUDED
#define OGRLIBKMLFIELDCONFIG_H_INCLUDED

/*******************************************************************************
 Function to fetch the field config options.
*******************************************************************************/

struct fieldconfig
{
    const char *idfield;
    const char *namefield;
    const char *descfield;
    const char *tsfield;
    const char *beginfield;
    const char *endfield;
    const char *altitudeModefield;
    const char *tessellatefield;
    const char *extrudefield;
    const char *visibilityfield;
    const char *drawOrderfield;
    const char *iconfield;
    const char *headingfield;
    const char *tiltfield;
    const char *rollfield;
    const char *snippetfield;
    const char *modelfield;
    const char *scalexfield;
    const char *scaleyfield;
    const char *scalezfield;
    const char *networklinkfield;
    const char *networklink_refreshvisibility_field;
    const char *networklink_flytoview_field;
    const char *networklink_refreshMode_field;
    const char *networklink_refreshInterval_field;
    const char *networklink_viewRefreshMode_field;
    const char *networklink_viewRefreshTime_field;
    const char *networklink_viewBoundScale_field;
    const char *networklink_viewFormat_field;
    const char *networklink_httpQuery_field;
    const char *camera_longitude_field;
    const char *camera_latitude_field;
    const char *camera_altitude_field;
    const char *camera_altitudemode_field;
    const char *photooverlayfield;
    const char *leftfovfield;
    const char *rightfovfield;
    const char *bottomfovfield;
    const char *topfovfield;
    const char *nearfield;
    const char *photooverlay_shape_field;
    const char *imagepyramid_tilesize_field;
    const char *imagepyramid_maxwidth_field;
    const char *imagepyramid_maxheight_field;
    const char *imagepyramid_gridorigin_field;
};

void get_fieldconfig(struct fieldconfig *oFC);

#endif
