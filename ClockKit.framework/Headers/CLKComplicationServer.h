//
//  CLKComplicationServer.h
//  ClockKit
//
//  Copyright © 2015 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@class CLKComplication;

extern NSString * const CLKComplicationServerActiveComplicationsDidChangeNotification;

@interface CLKComplicationServer : NSObject

+ (instancetype)sharedInstance;

@property (nonatomic, readonly) NSArray<CLKComplication *> *activeComplications;

- (void)reloadTimelineForComplication:(CLKComplication *)complication;
- (void)extendTimelineForComplication:(CLKComplication *)complication;

@end
