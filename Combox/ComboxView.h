//
//  ComboxView.h
//  Pointwelve
//
//  Created by Ryne Cheow on 8/5/15.
//
//


#import <UIKit/UIKit.h>

#define imgW 10
#define imgH 10
#define tableH 150
#define DEGREES_TO_RADIANS(angle) ((angle)/180.0 *M_PI)
#define kBorderColor [UIColor colorWithRed:219/255.0 green:217/255.0 blue:216/255.0 alpha:1]
#define kTextColor   [UIColor darkGrayColor]

@class ComboxView;

@protocol ComboxViewDelegate <NSObject>

- (void)selectAtIndex:(NSInteger)index
             inCombox:(ComboxView *)combox;

@end

@interface ComboxView : UIView <UITableViewDataSource, UITableViewDelegate> {
    UILabel *titleLabel;
}
@property(nonatomic, assign) BOOL isOpen;
@property(nonatomic, strong) UITableView *listTable;
@property(nonatomic, strong) NSMutableArray *titlesList;
@property(nonatomic, assign) int defaultIndex;
@property(nonatomic, assign) float tableHeight;
@property(nonatomic, strong) UIImageView *arrow;
@property(nonatomic, copy) NSString *arrowImgName;
@property(nonatomic, assign) id <ComboxViewDelegate> delegate;
@property(nonatomic, strong) UIView *supView;

- (void)defaultSettings;

- (void)reloadData;

- (void)closeOtherCombox;

- (void)tapAction;

@end