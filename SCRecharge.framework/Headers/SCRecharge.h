//
//  SCRecharge.h
//  SCRecharge
//
//  Created by SC on 17/1/20.
//  Copyright © 2017年 sc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

//! Project version number for SCRecharge.
FOUNDATION_EXPORT double SCRechargeVersionNumber;

//! Project version string for SCRecharge.
FOUNDATION_EXPORT const unsigned char SCRechargeVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <SCRecharge/PublicHeader.h>


/**
 SCRChargeStatus充值状态
 
 - SCRChargeSuccessed: 充值成功
 - SCRChargeFailed: 充值失败
 - SCRCharging: 正在充值中
 - SCRChargeTimeout: 充值超时
 - SCRChargeCanceled: 取消充值
 */
typedef NS_ENUM(NSInteger, SCRChargeStatus) {
    SCRChargeSuccessed = 1,
    SCRChargeFailed,
    SCRCharging,
    SCRChargeTimeout,
    SCRChargeCanceled
};

@interface SCRecharge : NSObject

/**
 SCRecharge单例

 @return SCRecharge单例;
 */
+(instancetype)sharedInstance;

-(instancetype) init __attribute__((unavailable("init not available")));

/**
 数创信息分配给用户的appKey，需要向数创信息申请
 */
@property(nonatomic, strong)NSString *appKey;

/**
 数创信息分配给用户的secret，需要向数创信息申请
 */
@property(nonatomic, strong)NSString *secret;

/**
 是否使能信息提醒，默认为YES
 */
@property(nonatomic, assign)BOOL disableMsgAlert;

/**
 是否使能debug模式，使能该项可在console中查看调试信息，默认为NO
 */
@property(nonatomic, assign)BOOL enableDebug;

/**
 SCRecharge启动方法

 @param appKey 数创信息分配给用户的appKey
 @param appKey 数创信息分配给用户的secret
 @param registerClasses 需要调用充值接口的类列表
                        注：Class必须为UIViewController及其子类
 @param handler 启动结果回调isSuccess为YES时表示成功，若为NO则以后的其他调用都不会成功
 */
- (void)startWithAppKey:(NSString *)appKey secret:(NSString *)secret registerClasses:(NSArray<Class>*)registerClasses handler:(void (^)(BOOL isSuccess))handler;

/**
 获取中石化安全验证码，开始充值方法需要用到该验证码
 
 @param viewController 该viewController所属类必须在startWithAppKey:secret:registerClasses:handler:接口中的registerClasses参数中
 @param cardNo 充值卡号
 @param phone 手机号
 @param handler 结果回调，isSuccessed 为返回值
 1.成功时isSuccessed为YES
 2.失败时isSuccessed为NO
 */
- (void)getSMSVerificationCode:(UIViewController *)viewController cardNo:(nonnull NSString *)cardNo phone:(nonnull NSString *)phone handler:(void(^ __nullable)(BOOL isSuccessed, NSError *__nullable error))handler;

/**
 生成数创后台充值订单，用户App在handler中调用支付（微支付等）相关接口
 
 @param viewController 该viewController所属类必须在startWithAppKey:secret:registerClasses:handler:接口中的registerClasses参数中
 @param cardNo 充值卡号
 @param phone 手机号
 @param amount 充值金额
 @param handler 结果回调，vorder_sn为数创信息后台充值订单编号, error为错误信息
 1.成功时vorder_sn为数创信息后台充值订单编号， error为nil
 2.失败时vorder_sn为nil， error为错误信息
 */
- (void)generateOrder:(UIViewController *)viewController cardNo:(nonnull NSString *)cardNo phone:(nonnull NSString *)phone amount:(nonnull NSString *)amount handler:(void (^ __nonnull)(NSString *__nullable vorder_sn,  NSError *__nullable error))handler;

/**
 开始充值，在用户调用支付（微支付等）前调用该接口
 
 @param viewController 该viewController所属类必须在startWithAppKey:secret:registerClasses:handler:接口中的registerClasses参数中
 @param vorder_sn 数创信息后台的充值订单编号
 @param verificationCode 中石化的安全验证码
 @param handler 结果回调，status为充值状态, error为错误信息
 1.status为SCRChargeSuccessed时表示充值成功， error为nil
 2.status为SCRChargeFailed时表示充值失败， error为失败信息
 3.status为SCRCharging时表示正在充值中， error为nil
 4.status为SCRChargeTimeout时表示充值超时， error为nil
 5.status为SCRChargeCanceled时表示充值取消， error为nil
 */
- (void)startCharge:(UIViewController *)viewController vorderSn:(nonnull NSString *)vorder_sn verificationCode:(nonnull NSString *)verificationCode handler:(void (^ __nonnull)(SCRChargeStatus  status,  NSError *__nullable error))handler;

/**
 取消充值，在用户取消支付时调用，如：用户App收到取消微支付后，应该调用该方法；
 @param viewController 该viewController所属类必须在startWithAppKey:secret:registerClasses:handler:接口中的registerClasses参数中
 */
- (void)cancelCharge:(UIViewController *)viewController;

@end
