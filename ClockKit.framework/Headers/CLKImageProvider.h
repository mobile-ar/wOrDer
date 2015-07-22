//
//  CLKImageProvider.h
//  ClockKit
//
//  Copyright © 2015 Apple Inc. All rights reserved.
//

#import <UIKit/UIImage.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, CLKImageProviderForegroundColor) {
    CLKImageProviderForegroundColorWhite,
    CLKImageProviderForegroundColorBlack
};

@interface CLKImageProvider : NSObject <NSCopying>

+ (instancetype)imageProviderWithBackgroundImage:(UIImage *)backgroundImage backgroundColor:(nullable UIColor *)backgroundColor;

+ (instancetype)imageProviderWithBackgroundImage:(UIImage *)backgroundImage backgroundColor:(nullable UIColor *)backgroundColor
                                 foregroundImage:(nullable UIImage *)foregroundImage foregroundColor:(CLKImageProviderForegroundColor)foregroundColor;

// Monochrome (template) image of the size specified in the complication template.
@property (nonatomic, nonnull) UIImage *backgroundImage;

// Tint color for the background image.
// This property will be ignored in contexts where image tint color is determined by the user's clock face configuration, and honored in multi-colored contexts.
@property (nonatomic, nullable) UIColor *backgroundColor;

// Monochrome (template) image of the same size as the backgroundImage.
// This image will be tinted black or white and overlayed on the backgroundImage.
@property (nonatomic, nullable) UIImage *foregroundImage;

// Tint color for the foreground image (limited to black or white).
// This property will be honored in the same contexts where the backgroundColor is honored.
@property (nonatomic) CLKImageProviderForegroundColor foregroundColor;

// Text for accessibility.
@property (nonatomic, nullable) NSString *accessibilityLabel;

@end

NS_ASSUME_NONNULL_END