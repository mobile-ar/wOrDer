//
//  CLKComplicationTimelineEntry.h
//  ClockKit
//
//  Copyright © 2015 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class CLKComplicationTemplate;

@interface CLKComplicationTimelineEntry : NSObject

+ (instancetype)entryWithDate:(NSDate *)date complicationTemplate:(CLKComplicationTemplate *)complicationTemplate;

@property (nonatomic) NSDate *date;
@property (nonatomic, copy) CLKComplicationTemplate *complicationTemplate;

@end

NS_ASSUME_NONNULL_END
