//
//  CLKTextProvider.h
//  ClockKit
//
//  Copyright © 2015 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CLKTextProvider : NSObject <NSCopying>
@end


#pragma mark - Simple

// Simple text providers display arbitrary text. If shortText is provided, we will fall back on it before truncating.
// If accessibilityLabel is provided, it will be used in place of the text property for VoiceOver.

@interface CLKSimpleTextProvider : CLKTextProvider

+ (instancetype)textProviderWithText:(NSString *)text;
+ (instancetype)textProviderWithText:(NSString *)text shortText:(nullable NSString *)shortText;
+ (instancetype)textProviderWithText:(nonnull NSString *)text shortText:(nullable NSString *)shortText accessibilityLabel:(nullable NSString *)accessibilityLabel;

@property (nonatomic, copy) NSString *text;
@property (nonatomic, copy, nullable) NSString *shortText;

@property (nonatomic, copy, nullable) NSString *accessibilityLabel;

@end


#pragma mark - Date

// Date text providers can display any subset of the following calendar units:
//    NSCalendarUnitYear
//    NSCalendarUnitMonth
//    NSCalendarUnitDay
//    NSCalendarUnitWeekday
// Unsupported calendar units will be ignored.
//
// We will attempt to include all of the requested units in the output string, but will drop units before truncating.
//
// For example, if you ask for Weekday, Month, and Day units, and the locale is English-US, we would attempt the following outputs in order, space permitting:
//    Wednesday, December 23
//    Wednesday, Dec 23
//    Wed, Dec 23
//    Dec 23
//    23

@interface CLKDateTextProvider : CLKTextProvider

+ (instancetype)textProviderWithDate:(NSDate *)date units:(NSCalendarUnit)calendarUnits;
+ (instancetype)textProviderWithDate:(NSDate *)date units:(NSCalendarUnit)calendarUnits timeZone:(nullable NSTimeZone *)timeZone;

@property (nonatomic) NSDate *date;
@property (nonatomic) NSCalendarUnit calendarUnits;
@property (nonatomic, nullable) NSTimeZone *timeZone;

@end


#pragma mark - Time

// Time text providers will display a time in one of the following two formats, depending on the available space:
//   11:23PM
//   11:23

@interface CLKTimeTextProvider : CLKTextProvider

+ (instancetype)textProviderWithDate:(NSDate *)date;
+ (instancetype)textProviderWithDate:(NSDate *)date timeZone:(nullable NSTimeZone *)timeZone;

@property (nonatomic) NSDate *date;
@property (nonatomic, nullable) NSTimeZone *timeZone;

@end


#pragma mark - Time Interval

// Time interval text providers will display a date range in a variety of different ways, depending on the size of the interval and the available space:
//
// Some examples:
//   If one date is in the AM and the other is in the PM:
//      9:30AM - 3:30PM
//   If both dates are in the AM (or PM):
//      9:30 - 10:30AM
//      9:30 - 10:30PM
//   If interval is greater than 24 hours:
//      Jan 1 - Jan 7
//      1/1 - 1/7
//
// If space is constrained, this text provider will fall back on showing only the startDate before truncating.

@interface CLKTimeIntervalTextProvider : CLKTextProvider

+ (instancetype)textProviderWithStartDate:(NSDate *)startDate endDate:(NSDate *)endDate;
+ (instancetype)textProviderWithStartDate:(NSDate *)startDate endDate:(NSDate *)endDate timeZone:(nullable NSTimeZone *)timeZone;

@property (nonatomic) NSDate *startDate;
@property (nonatomic) NSDate *endDate;
@property (nonatomic, nullable) NSTimeZone *timeZone;

@end


#pragma mark - Relative Date

// Relative date text providers display the difference between now and the provided date.
//
// They support the following calendar units:
//    NSCalendarUnitYear
//    NSCalendarUnitMonth
//    NSCalendarUnitWeekOfMonth (used to mean "quantity of weeks")
//    NSCalendarUnitDay
//    NSCalendarUnitHour
//    NSCalendarUnitMinute
//    NSCalendarUnitSecond
//
// Three formatting styles are supported.
//    Natural:
//       Now
//       2hrs 7mins
//       13mins 5secs
//       3wks 4days
//       2yrs 3mos
//    Offset:
//       Now
//       +14 seconds
//       -59 minutes
//       +2 hours
//       -6 days
//       +12 weeks
//    Timer (only supports hours, minutes, seconds):
//       02:32
//       21:15:59

typedef NS_ENUM(NSInteger, CLKRelativeDateStyle) {
    CLKRelativeDateStyleNatural,
    CLKRelativeDateStyleOffset,
    CLKRelativeDateStyleTimer,
};

@interface CLKRelativeDateTextProvider : CLKTextProvider

+ (instancetype)textProviderWithDate:(NSDate *)date style:(CLKRelativeDateStyle)style units:(NSCalendarUnit)calendarUnits;

@property (nonatomic) NSDate *date;
@property (nonatomic) CLKRelativeDateStyle relativeDateStyle;
@property (nonatomic) NSCalendarUnit calendarUnits;

@end

NS_ASSUME_NONNULL_END
