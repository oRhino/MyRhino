//
//  CGGradientRef.h
//  HeaderNote
//
//  Created by Rhino on 2017/7/26.
//  Copyright © 2017年 Rhino. All rights reserved.
//

#ifndef CGGradientRef_h
#define CGGradientRef_h



//渐变
#ifndef CGGRADIENT_H_
#define CGGRADIENT_H_

#include <CoreFoundation/CFBase.h>
#include <CoreFoundation/CFAvailability.h>
#include <stdint.h>

typedef struct CF_BRIDGED_TYPE(id) CGGradient *CGGradientRef;

typedef CF_OPTIONS (uint32_t, CGGradientDrawingOptions) {
    //扩展填充起始点之前的区域
    kCGGradientDrawsBeforeStartLocation = (1 << 0),
    //扩展填充结束点之后的区域
    kCGGradientDrawsAfterEndLocation = (1 << 1)
};

#include <CoreGraphics/CGBase.h>
#include <CoreGraphics/CGColorSpace.h>
#include <CoreGraphics/CGContext.h>

CF_IMPLICIT_BRIDGING_ENABLED

CF_ASSUME_NONNULL_BEGIN

/* A CGGradient defines a transition between colors. The transition is
 defined over a range from 0 to 1 inclusive. A gradient specifies a color
 at location 0, one at location 1, and possibly additional colors assigned
 to locations between 0 and 1.
 
 A CGGradient has a color space. When a gradient is created, all colors
 specified are converted to that color space, and interpolation of colors
 occurs using the components of that color space. See the documentation of
 each creation function for more details. */

/* Return the CFTypeID for CGGradients. */

CG_EXTERN CFTypeID CGGradientGetTypeID(void)
CG_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/* Creates a gradient by pairing the color components provided in
 `components' with locations provided in `locations'. If `locations' is
 NULL, the first color in `colors' will be at location 0, the last color
 in `colors' will be at location 1, and intervening colors will be at
 equal intervals in between. Otherwise, each location in `locations'
 should be a CGFloat between 0 and 1. Each set of color components should
 specify a color in the color space `space' (which may not be a pattern or
 indexed color space). The number of locations is specified by `count';
 the number of color components is the product of `count' and the number
 of color components of `space'. If no color is provided for 0 or 1, the
 gradient will use the color provided at the locations closest to 0 and 1
 for those values. */

//创建渐变对象
//参数1:颜色空间(RGB,CMYK,YUV,Gray...)
//参数2:数组,根据不同的颜色空间设置多种颜色
//参数3:数组,指定个颜色点的分布位置,如果指定NULL,各颜色点会均匀分布
//参数4:指定该渐变包含多少种颜色.
CG_EXTERN CGGradientRef __nullable CGGradientCreateWithColorComponents(
                                                                       CGColorSpaceRef cg_nullable space, const CGFloat * cg_nullable components,
                                                                       const CGFloat * __nullable locations, size_t count)
CG_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/* Creates a gradient by pairing the colors provided in `colors' with the
 locations provided in `locations'. `colors' should be a non-empty array
 of CGColor objects. The colors may be in any color space other than a
 pattern or indexed color space. If `space' is non-NULL, each color will
 be converted to that color space and the gradient will drawn in that
 space; otherwise, each color will be converted to and drawn in the
 "Generic" RGB color space. If `space' is specified, it may not be a
 pattern or indexed color space. If `locations' is NULL, the first color
 in `colors' will be at location 0, the last color in `colors' will be at
 location 1, and intervening colors will be at equal intervals in between.
 Otherwise, each location in `locations' should be a CGFloat between 0 and
 1; the array of locations should should contain the same number of items
 as `colors'. If no color is provided for 0 or 1, the gradient will use
 the color provided at the locations closest to 0 and 1 for those
 values. */

CG_EXTERN CGGradientRef __nullable CGGradientCreateWithColors(
                                                              CGColorSpaceRef __nullable space, CFArrayRef cg_nullable colors,
                                                              const CGFloat * __nullable locations)
CG_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/* Equivalent to `CFRetain' except that it doesn't crash (as `CFRetain'
 does) if `gradient' is NULL. */

CG_EXTERN CGGradientRef cg_nullable CGGradientRetain(
                                                     CGGradientRef cg_nullable gradient)
CG_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/* Equivalent to `CFRelease' except that it doesn't crash (as `CFRelease'
 does) if `gradient' is NULL. */

CG_EXTERN void CGGradientRelease(CGGradientRef cg_nullable gradient)
CG_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

CF_ASSUME_NONNULL_END

CF_IMPLICIT_BRIDGING_DISABLED

#endif /* CGGRADIENT_H_ */




#endif /* CGGradientRef_h */