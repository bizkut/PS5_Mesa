/* SPDX-License-Identifier: MIT */
#include <assert.h>
#include "wsi_videoout_hdr.h"

int
main(void)
{
   uint64_t token = 0;
   assert(!videoout_hdr_declared(0));
   assert(!videoout_hdr_declared(0x40000000));
   assert(videoout_hdr_declared(0x20000001));
   assert(!videoout_hdr_pixel_format(false, VK_FORMAT_A2B10G10R10_UNORM_PACK32,
                                     VK_COLOR_SPACE_HDR10_ST2084_EXT, &token));
   assert(videoout_hdr_pixel_format(true, VK_FORMAT_A2B10G10R10_UNORM_PACK32,
                                    VK_COLOR_SPACE_HDR10_ST2084_EXT, &token));
   assert(token == UINT64_C(0x8100070422000000));
   assert(videoout_hdr_pixel_format(true, VK_FORMAT_A2R10G10B10_UNORM_PACK32,
                                    VK_COLOR_SPACE_HDR10_ST2084_EXT, &token));
   assert(token == UINT64_C(0x8100070400000000));
   assert(!videoout_hdr_pixel_format(true, VK_FORMAT_B8G8R8A8_UNORM,
                                     VK_COLOR_SPACE_HDR10_ST2084_EXT, &token));
   assert(!videoout_hdr_pixel_format(true, VK_FORMAT_A2B10G10R10_UNORM_PACK32,
                                     VK_COLOR_SPACE_SRGB_NONLINEAR_KHR, &token));
   return 0;
}
