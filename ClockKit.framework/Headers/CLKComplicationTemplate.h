//
//  CLKComplicationTemplate.h
//  ClockKit
//
//  Copyright © 2015 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ClockKit/CLKDefines.h>

@class CLKTextProvider;
@class CLKImageProvider;

NS_ASSUME_NONNULL_BEGIN

@interface CLKComplicationTemplate : NSObject <NSCopying>
@end

#pragma mark - Modular Small

@interface CLKComplicationTemplateModularSmallSimpleText : CLKComplicationTemplate
@property (nonatomic, copy) CLKTextProvider *textProvider;
@end

@interface CLKComplicationTemplateModularSmallSimpleImage : CLKComplicationTemplate
@property (nonatomic, copy) CLKImageProvider *imageProvider;
@end

@interface CLKComplicationTemplateModularSmallRingText : CLKComplicationTemplate
@property (nonatomic, copy) CLKTextProvider *textProvider;
@property (nonatomic) float fillFraction;
@property (nonatomic) CLKComplicationRingStyle ringStyle;
@end

@interface CLKComplicationTemplateModularSmallRingImage : CLKComplicationTemplate
@property (nonatomic, copy) CLKImageProvider *imageProvider;
@property (nonatomic) float fillFraction;
@property (nonatomic) CLKComplicationRingStyle ringStyle;
@end

@interface CLKComplicationTemplateModularSmallStackText : CLKComplicationTemplate
@property (nonatomic, copy) CLKTextProvider *line1TextProvider;
@property (nonatomic, copy) CLKTextProvider *line2TextProvider;
@end

@interface CLKComplicationTemplateModularSmallStackImage : CLKComplicationTemplate
@property (nonatomic, copy) CLKImageProvider *line1ImageProvider;
@property (nonatomic, copy) CLKTextProvider  *line2TextProvider;
@end

@interface CLKComplicationTemplateModularSmallColumnsText : CLKComplicationTemplate
@property (nonatomic, copy) CLKTextProvider *row1Column1TextProvider;
@property (nonatomic, copy) CLKTextProvider *row1Column2TextProvider;
@property (nonatomic, copy) CLKTextProvider *row2Column1TextProvider;
@property (nonatomic, copy) CLKTextProvider *row2Column2TextProvider;
@property (nonatomic) CLKComplicationColumnAlignment column2Alignment;
@property (nonatomic) BOOL highlightColumn2;
@end

#pragma mark - Modular Large

@interface CLKComplicationTemplateModularLargeStandardBody : CLKComplicationTemplate
@property (nonatomic, copy)  CLKTextProvider  *headerTextProvider;
@property (nonatomic, copy)  CLKTextProvider  *body1TextProvider;
@property (nonatomic, copy, nullable) CLKTextProvider  *body2TextProvider; // optional. if omitted, the first line of body text will be allowed to wrap.
@property (nonatomic, copy, nullable) CLKImageProvider *headerImageProvider;
@end

@interface CLKComplicationTemplateModularLargeTallBody : CLKComplicationTemplate
@property (nonatomic, copy) CLKTextProvider  *headerTextProvider;
@property (nonatomic, copy) CLKTextProvider  *bodyTextProvider;
@end

@interface CLKComplicationTemplateModularLargeTable : CLKComplicationTemplate
@property (nonatomic, copy)  CLKTextProvider  *headerTextProvider;
@property (nonatomic, copy)  CLKTextProvider  *row1Column1TextProvider;
@property (nonatomic, copy)  CLKTextProvider  *row1Column2TextProvider;
@property (nonatomic, copy)  CLKTextProvider  *row2Column1TextProvider;
@property (nonatomic, copy)  CLKTextProvider  *row2Column2TextProvider;
@property (nonatomic, copy, nullable) CLKImageProvider *headerImageProvider;
@property (nonatomic) CLKComplicationColumnAlignment column2Alignment;
@end

@interface CLKComplicationTemplateModularLargeColumns : CLKComplicationTemplate
@property (nonatomic, copy)  CLKTextProvider  *row1Column1TextProvider;
@property (nonatomic, copy)  CLKTextProvider  *row1Column2TextProvider;
@property (nonatomic, copy)  CLKTextProvider  *row2Column1TextProvider;
@property (nonatomic, copy)  CLKTextProvider  *row2Column2TextProvider;
@property (nonatomic, copy)  CLKTextProvider  *row3Column1TextProvider;
@property (nonatomic, copy)  CLKTextProvider  *row3Column2TextProvider;
@property (nonatomic, copy, nullable) CLKImageProvider *row1ImageProvider;
@property (nonatomic, copy, nullable) CLKImageProvider *row2ImageProvider;
@property (nonatomic, copy, nullable) CLKImageProvider *row3ImageProvider;
@property (nonatomic) CLKComplicationColumnAlignment column2Alignment;
@end

#pragma mark - Utilitarian Small

@interface CLKComplicationTemplateUtilitarianSmallFlat : CLKComplicationTemplate
@property (nonatomic, copy) CLKTextProvider *textProvider;
@property (nonatomic, copy, nullable) CLKImageProvider *imageProvider;
@end

@interface CLKComplicationTemplateUtilitarianSmallSquare : CLKComplicationTemplate
@property (nonatomic, copy) CLKImageProvider *imageProvider;
@end

@interface CLKComplicationTemplateUtilitarianSmallRingText : CLKComplicationTemplate
@property (nonatomic, copy) CLKTextProvider *textProvider;
@property (nonatomic) float fillFraction;
@property (nonatomic) CLKComplicationRingStyle ringStyle;
@end

@interface CLKComplicationTemplateUtilitarianSmallRingImage : CLKComplicationTemplate
@property (nonatomic, copy) CLKImageProvider *imageProvider;
@property (nonatomic) float fillFraction;
@property (nonatomic) CLKComplicationRingStyle ringStyle;
@end


#pragma mark - Utilitarian Large

@interface CLKComplicationTemplateUtilitarianLargeFlat : CLKComplicationTemplate
@property (nonatomic, copy) CLKTextProvider *textProvider;
@property (nonatomic, copy, nullable) CLKImageProvider *imageProvider;
@end

#pragma mark - Circular Small

@interface CLKComplicationTemplateCircularSmallSimpleText : CLKComplicationTemplate
@property (nonatomic, copy) CLKTextProvider *textProvider;
@end

@interface CLKComplicationTemplateCircularSmallSimpleImage : CLKComplicationTemplate
@property (nonatomic, copy) CLKImageProvider *imageProvider;
@end

@interface CLKComplicationTemplateCircularSmallRingText : CLKComplicationTemplate
@property (nonatomic, copy) CLKTextProvider *textProvider;
@property (nonatomic) float fillFraction;
@property (nonatomic) CLKComplicationRingStyle ringStyle;
@end

@interface CLKComplicationTemplateCircularSmallRingImage : CLKComplicationTemplate
@property (nonatomic, copy) CLKImageProvider *imageProvider;
@property (nonatomic) float fillFraction;
@property (nonatomic) CLKComplicationRingStyle ringStyle;
@end

@interface CLKComplicationTemplateCircularSmallStackText : CLKComplicationTemplate
@property (nonatomic, copy) CLKTextProvider *line1TextProvider;
@property (nonatomic, copy) CLKTextProvider *line2TextProvider;
@end

@interface CLKComplicationTemplateCircularSmallStackImage : CLKComplicationTemplate
@property (nonatomic, copy) CLKImageProvider *line1ImageProvider;
@property (nonatomic, copy) CLKTextProvider  *line2TextProvider;
@end

NS_ASSUME_NONNULL_END

