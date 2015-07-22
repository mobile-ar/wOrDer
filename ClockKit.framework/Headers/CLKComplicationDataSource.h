//
//  CLKComplicationDataSource.h
//  ClockKit
//
//  Copyright © 2015 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ClockKit/CLKDefines.h>

NS_ASSUME_NONNULL_BEGIN

@class CLKComplication;
@class CLKComplicationTemplate;
@class CLKComplicationTimelineEntry;

@protocol CLKComplicationDataSource <NSObject>

#pragma mark Timeline Configuration

/// Provide the time travel directions your complication supports (forward, backward, both, or none).
- (void)getSupportedTimeTravelDirectionsForComplication:(CLKComplication *)complication withHandler:(void(^)(CLKComplicationTimeTravelDirections directions))handler;

/// Depending on which time travel directions you support, you will be asked for the start/end dates of your timeline (or both, or neither).
/// The start/end dates will determine at what point during time travel we dim out your data to indicate that the timeline does not continue in this direction.
/// Timeline entries after the timeline end date or before the timeline start date will not be displayed.
- (void)getTimelineStartDateForComplication:(CLKComplication *)complication withHandler:(void(^)(__nullable NSDate *date))handler;
- (void)getTimelineEndDateForComplication:(CLKComplication *)complication withHandler:(void(^)(__nullable NSDate *date))handler;

/// Indicate whether your complication's data should be hidden when the watch is locked.
- (void)getPrivacyBehaviorForComplication:(CLKComplication *)complication withHandler:(void(^)(CLKComplicationPrivacyBehavior privacyBehavior))handler;

#pragma mark Timeline Population

/// Provide the entry that should currently be displayed.
/// If you pass back nil, we will conclude you have no content loaded and will stop talking to you until you next call -reloadTimelineForComplication:.
- (void)getCurrentTimelineEntryForComplication:(CLKComplication *)complication withHandler:(void(^)(__nullable CLKComplicationTimelineEntry *))handler;

/// The owning complication will use these methods to extend its timeline backwards or forwards.
/// @param date The date of the first/last entry we already have. Return the batch of entries before/after this date.
/// @param limit Maximum number of entries to return.
- (void)getTimelineEntriesForComplication:(CLKComplication *)complication beforeDate:(NSDate *)date limit:(NSUInteger)limit
                              withHandler:(void(^)(__nullable NSArray<CLKComplicationTimelineEntry *> *entries))handler;
- (void)getTimelineEntriesForComplication:(CLKComplication *)complication afterDate:(NSDate *)date limit:(NSUInteger)limit
                              withHandler:(void(^)(__nullable NSArray<CLKComplicationTimelineEntry *> *entries))handler;


#pragma mark Update Scheduling

/// Return the date when you would next like to be given the opportunity to update your complication content.
/// We will make an effort to launch you at or around that date, subject to power and budget limitations.
- (void)getNextRequestedUpdateDateWithHandler:(void(^)(__nullable NSDate *updateDate))handler;

#pragma mark - Placeholder Templates

/// When your extension is installed, this method will be called once per supported complication, and the results will be cached.
/// If you pass back nil, we will use the default placeholder template (which is a combination of your icon and app name).
- (void)getPlaceholderTemplateForComplication:(CLKComplication *)complication withHandler:(void(^)(__nullable CLKComplicationTemplate *complicationTemplate))handler;

@end

NS_ASSUME_NONNULL_END