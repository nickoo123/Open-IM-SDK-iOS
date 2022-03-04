//
//  OIMCallbacker.h
//  OpenIMSDK
//
//  Created by x on 2022/2/11.
//

#import <Foundation/Foundation.h>
#import <MJExtension/MJExtension.h>

#import "OIMDefine.h"
#import "OIMUserInfo.h"
#import "OIMFullUserInfo.h"
#import "OIMFriendApplication.h"
#import "OIMGroupApplicationInfo.h"
#import "OIMGroupInfo.h"
#import "OIMGroupMemberInfo.h"
#import "OIMConversationInfo.h"
#import "OIMMessageInfo.h"
#import "OIMReceiptInfo.h"
#import "OIMSearchParam.h"
#import "OIMSearchResultInfo.h"
#import "OIMSimpleResultInfo.h"
#import "OIMSimpleRequstInfo.h"

@import OpenIMCore;

NS_ASSUME_NONNULL_BEGIN


typedef void (^OIMSimpleResultCallback)(OIMSimpleResultInfo * _Nullable result);
typedef void (^OIMSimpleResultsCallback)(NSArray <OIMSimpleResultInfo *> * _Nullable results);

typedef void (^OIMUserInfoCallback)(OIMUserInfo * _Nullable userInfo);
typedef void (^OIMUsersCallback)(NSArray <OIMFullUserInfo *> * _Nullable userInfos);
typedef void (^OIMFullUserInfoCallback)(OIMFullUserInfo * _Nullable userInfo);
typedef void (^OIMFullUsersInfoCallback)(NSArray <OIMFullUserInfo *> * _Nullable userInfos);
typedef void (^OIMBlacksInfoCallback)(NSArray <OIMBlackInfo *> * _Nullable blackInfos);

typedef void (^OIMFriendApplicationCallback)(OIMFriendApplication * _Nullable friendApplication);
typedef void (^OIMFriendApplicationsCallback)(NSArray <OIMFriendApplication *> * _Nullable friendApplications);

typedef void (^OIMFriendInfoCallback)(OIMFriendInfo * _Nullable friendInfo);
typedef void (^OIMBlackInfoCallback)(OIMBlackInfo * _Nullable blackInfo);

typedef void (^OIMGroupApplicationCallback)(OIMGroupApplicationInfo * _Nullable groupApplication);
typedef void (^OIMGroupsApplicationCallback)(NSArray <OIMGroupApplicationInfo *> * _Nullable groupsInfo);
typedef void (^OIMGroupInfoCallback)(OIMGroupInfo * _Nullable groupInfo);
typedef void (^OIMGroupsInfoCallback)(NSArray <OIMGroupInfo *> * _Nullable groupsInfo);
typedef void (^OIMGroupMemberInfoCallback)(OIMGroupMemberInfo * _Nullable groupMemberInfo);
typedef void (^OIMGroupMembersInfoCallback)(NSArray <OIMGroupMemberInfo *> * _Nullable groupMembersInfo);

typedef void (^OIMConversationsInfoCallback)(NSArray <OIMConversationInfo *> * _Nullable conversations);
typedef void (^OIMConversationInfoCallback)(OIMConversationInfo * _Nullable conversation);
typedef void (^OIMConversationNotDisturbInfoCallback)(NSArray <OIMConversationNotDisturbInfo *> * _Nullable conversations);

typedef void (^OIMMessageInfoCallback)(OIMMessageInfo * _Nullable message);
typedef void (^OIMMessagesInfoCallback)(NSArray <OIMMessageInfo *> * _Nullable messages);
typedef void (^OIMMessageSearchCallback)(OIMSearchResultInfo * _Nullable result);

typedef void (^OIMReceiptCallback)(NSArray <OIMReceiptInfo *> * _Nullable msgReceiptList);

/// 资料关系链回调
@protocol OIMFriendshipListener <NSObject>
@optional

/*
 *  好友申请新增通知
 */
- (void)onFriendApplicationAdded:(OIMFriendApplication *)application;

/*
 *  好友申请被拒绝
 */
- (void)onFriendApplicationRejected:(OIMFriendApplication *)application;

/*
 *  好友申请被接受
 */
- (void)onFriendApplicationAccepted:(OIMFriendApplication *)application;

/*
 *  好友申请被删除
 */
- (void)onFriendApplicationDeleted:(OIMFriendApplication *)application;

/*
 *  好友新增通知
 */
- (void)onFriendAdded:(OIMFriendInfo *)info;

/*
 *  好友删除通知
 */
- (void)onFriendDeleted:(OIMFriendInfo *)info;

/*
 *  好友资料变更通知
 */
- (void)onFriendInfoChanged:(OIMFriendInfo *)info;

/*
 *  黑名单新增通知
 */
- (void)onBlackAdded:(OIMBlackInfo *)info;

/*
 *  黑名单删除通知
 */
- (void)onBlackDeleted:(OIMBlackInfo *)info;

@end

/// IMSDK 群组事件回调
@protocol OIMGroupListener <NSObject>
@optional

/*
 *  有新成员加入群
 */
- (void)onGroupMemberAdded:(OIMGroupMemberInfo *)memberInfo;

/*
 *  有成员离开群
 */
- (void)onGroupMemberDeleted:(OIMGroupMemberInfo *)memberInfo;

/*
 *  某成员信息发生变更
 */
- (void)onGroupMemberInfoChanged:(OIMGroupMemberInfo *)changeInfo;

/*
 *  例如有邀请进群， UI列表会展示新的item
 */
- (void)onJoinedGroupAdded:(OIMGroupInfo *)groupInfo;

/*
 *  例如群里被踢， UI列表会删除这个的item
 */
- (void)onJoinedGroupDeleted:(OIMGroupInfo *)groupInfo;

/*
 *  某个已加入的群的信息被修改了
 */
- (void)onGroupInfoChanged:(OIMGroupInfo *)changeInfo;

/*
 *  群申请被接受
 */
- (void)onGroupApplicationAccepted:(OIMGroupApplicationInfo *)groupApplication;

/*
 *  有人申请加群
 */
- (void)onGroupApplicationAdded:(OIMGroupApplicationInfo *)groupApplication;

/*
 *  群申请有删除
 */
- (void)onGroupApplicationDeleted:(OIMGroupApplicationInfo *)groupApplication;

/*
 *  群申请有拒绝
 */
- (void)onGroupApplicationRejected:(OIMGroupApplicationInfo *)groupApplication;

@end

@protocol OIMConversationListener <NSObject>
@optional

/*
 * 同步服务器会话开始
 */
- (void)onSyncServerStart;

/*
 * 同步服务器会话完成
 */
- (void)onSyncServerFinish;

/*
 * 同步服务器会话失败
 */
- (void)onSyncServerFailed;

/*
 * 有新的会话
 */
- (void)onNewConversation:(NSArray <OIMConversationInfo *> *) conversations;

/*
 * 某些会话的关键信息发生变化（
 */
- (void)onConversationChanged:(NSArray <OIMConversationInfo *> *)conversations;

/*
 * 会话未读总数变更通知
 */
- (void)onTotalUnreadMessageCountChanged:(NSInteger) totalUnreadCount;

@end

/// 高级消息监听器
@protocol OIMAdvancedMsgListener <NSObject>
@optional

/*
 *  收到新消息
 */
- (void)onRecvNewMessage:(OIMMessageInfo *)msg;

/*
 *  收到消息已读回执（仅单聊有效）
 */
- (void)onRecvC2CReadReceipt:(NSArray<OIMReceiptInfo *> *)receiptList;

/*
 *  收到消息撤回
 */
- (void)onRecvMessageRevoked:(NSString *)msgID;

@end

@interface OIMCallbacker : NSObject
<
Open_im_sdk_callbackOnAdvancedMsgListener,
Open_im_sdk_callbackOnConversationListener,
Open_im_sdk_callbackOnFriendshipListener,
Open_im_sdk_callbackOnGroupListener,
Open_im_sdk_callbackOnUserListener
>

+ (instancetype)callbacker;

- (void)setListener;

/// 链接监听
/// 在InitSDK时设置，在IM连接状态有变化时回调
@property (nonatomic, nullable, copy) OIMVoidCallback onConnecting;
@property (nonatomic, nullable, copy) OIMFailureCallback onConnectFailure;
@property (nonatomic, nullable, copy) OIMVoidCallback onConnectSuccess;
@property (nonatomic, nullable, copy) OIMVoidCallback onKickedOffline;
@property (nonatomic, nullable, copy) OIMVoidCallback onUserTokenExpired;

/// 用户监听
/// 在InitSDK成功后，Login之前设置，本登录用户个人资料有变化时回调
/// 可调用OIMCallbacker+User相关函数设置所有监
@property (nonatomic, nullable, copy) OIMUserInfoCallback onSelfInfoUpdated;

/// 好友监听
/// 在InitSDK成功后，Login之前设置，好友相关信息有变化时回调
/// 可调用OIMCallbacker+Friend相关函数设置所有监听
@property (nonatomic, nullable, copy) OIMFriendApplicationCallback onFriendApplicationAdded;
@property (nonatomic, nullable, copy) OIMFriendApplicationCallback onFriendApplicationDeleted;
@property (nonatomic, nullable, copy) OIMFriendApplicationCallback onFriendApplicationAccepted;
@property (nonatomic, nullable, copy) OIMFriendApplicationCallback onFriendApplicationRejected;
@property (nonatomic, nullable, copy) OIMFriendInfoCallback onFriendAdded;
@property (nonatomic, nullable, copy) OIMFriendInfoCallback onFriendDeleted;
@property (nonatomic, nullable, copy) OIMFriendInfoCallback onFriendInfoChanged;
@property (nonatomic, nullable, copy) OIMBlackInfoCallback onBlackAdded;
@property (nonatomic, nullable, copy) OIMBlackInfoCallback onBlackDeleted;

/**
 *  添加关系链监听器
 */
- (void)addFriendListener:(id<OIMFriendshipListener>)listener NS_SWIFT_NAME(addFriendListener(listener:));

/**
 *   移除关系链监听器
 */
- (void)removeFriendListener:(id<OIMFriendshipListener>)listener NS_SWIFT_NAME(removeFriendListener(listener:));

/// 群组监听
/// 在InitSDK成功后，Login之前设置，群组相关信息有变化时回调
/// 可调用OIMCallbacker+Group相关函数设置所有监听
@property (nonatomic, nullable, copy) OIMGroupInfoCallback onGroupInfoChanged;
@property (nonatomic, nullable, copy) OIMGroupInfoCallback onJoinedGroupAdded;
@property (nonatomic, nullable, copy) OIMGroupInfoCallback onJoinedGroupDeleted;
@property (nonatomic, nullable, copy) OIMGroupMemberInfoCallback onGroupMemberAdded;
@property (nonatomic, nullable, copy) OIMGroupMemberInfoCallback onGroupMemberDeleted;
@property (nonatomic, nullable, copy) OIMGroupMemberInfoCallback onGroupMemberInfoChanged;
@property (nonatomic, nullable, copy) OIMGroupApplicationCallback onGroupApplicationAdded;
@property (nonatomic, nullable, copy) OIMGroupApplicationCallback onGroupApplicationDeleted;
@property (nonatomic, nullable, copy) OIMGroupApplicationCallback onGroupApplicationAccepted;
@property (nonatomic, nullable, copy) OIMGroupApplicationCallback onGroupApplicationRejected;

/*
 *  设置群组监听器
 */
- (void)addGroupListener:(id<OIMGroupListener>)listener NS_SWIFT_NAME(addGroupListener(listener:));

/*
 *  设置群组监听器
 */
- (void)removeGroupListener:(id<OIMGroupListener>)listener NS_SWIFT_NAME(removeGroupListener(listener:));

/// 会话监听
/// 在InitSDK成功后，Login之前设置，群组相关信息有变化时回调
/// 可调用OIMCallbacker+Conversation相关函数设置所有监听
@property (nonatomic, nullable, copy) OIMVoidCallback syncServerStart;
@property (nonatomic, nullable, copy) OIMVoidCallback syncServerFinish;
@property (nonatomic, nullable, copy) OIMVoidCallback syncServerFailed;
@property (nonatomic, nullable, copy) OIMConversationsInfoCallback onNewConversation;
@property (nonatomic, nullable, copy) OIMConversationsInfoCallback onConversationChanged;
@property (nonatomic, nullable, copy) OIMNumberCallback onTotalUnreadMessageCountChanged;

/*
 *  添加会话监听器
 */
- (void)addConversationListener:(id<OIMConversationListener>)listener NS_SWIFT_NAME(addConversationListener(listener:));

/*
 *  移除会话监听器
 */
- (void)removeConversationListener:(id<OIMConversationListener>)listener NS_SWIFT_NAME(removeConversationListener(listener:));

/// 消息监听
/// 在InitSDK成功后，Login之前设置，群组相关信息有变化时回调
/// 可调用OIMCallbacker+Message相关函数设置所有监听
@property (nonatomic, nullable, copy) OIMMessageInfoCallback onRecvNewMessage;
@property (nonatomic, nullable, copy) OIMReceiptCallback onRecvC2CReadReceipt;
@property (nonatomic, nullable, copy) OIMStringCallback onRecvMessageRevoked;

/*
 *  添加高级消息的事件监听器
 */
- (void)addAdvancedMsgListener:(id<OIMAdvancedMsgListener>)listener NS_SWIFT_NAME(addAdvancedMsgListener(listener:));

/*
 *  移除高级消息的事件监听器
 */
- (void)removeAdvancedMsgListener:(id<OIMAdvancedMsgListener>)listener NS_SWIFT_NAME(removeAdvancedMsgListener(listener:));
@end

NS_ASSUME_NONNULL_END
