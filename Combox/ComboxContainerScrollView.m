//
//  ComboxContainerScrollView.m
//  Pointwelve
//
//  Created by Ryne Cheow on 8/5/15.
//
//


#import "ComboxContainerScrollView.h"
#import "ComboxView.h"

@implementation ComboxContainerScrollView

- (id)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        // Initialization code
    }
    return self;
}

- (void)closeAllComboxView
{
    for (UIView *subView in self.subviews) {
        if ([subView isKindOfClass:[ComboxView class]]) {
            ComboxView *combox = (ComboxView *) subView;
            if (combox.isOpen) {
                [UIView animateWithDuration:0.3 animations:^{
                    CGRect frame = combox.listTable.frame;
                    frame.size.height = 0;
                    [combox.listTable setFrame:frame];
                }                completion:^(BOOL finished) {
                    [combox.listTable removeFromSuperview];
                    combox.isOpen = NO;
                    combox.arrow.transform = CGAffineTransformRotate(combox.arrow.transform, (CGFloat) DEGREES_TO_RADIANS(180));
                }];
            }
        }
    }
}

- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event
{
    [self closeAllComboxView];
}


@end
