type t;

type visibility = [ | `GONE | `VISIBLE];

[@bs.deriving abstract]
type attributes_companies = {
  [@bs.optional]
  company_id: string,
  [@bs.optional]
  name: string,
  [@bs.optional]
  created_at: int,
  [@bs.optional]
  monthly_spend: int,
  [@bs.optional]
  plan: string,
};

[@bs.deriving abstract]
type attributes = {
  [@bs.optional]
  email: string,
  [@bs.optional]
  user_id: string,
  [@bs.optional]
  name: string,
  [@bs.optional]
  phone: string,
  [@bs.optional]
  language_override: string,
  [@bs.optional]
  signed_up_at: int,
  [@bs.optional]
  unsubscribed_from_emails: bool,
  [@bs.optional]
  companies: attributes_companies,
};
[@bs.deriving abstract]
type options = {
  [@bs.optional]
  userId: string,
  [@bs.optional]
  email: string,
};
/**
 * Log an event
 * @param {string} eventName
 * @param {[key: string]: string} metadata
 */
type metadata;
type logEvent = {
  eventName: string,
  metadata,
};

[@bs.module "react-native-intercom"] [@bs.scope "default"]
external registerIdentifiedUser: options => Js.Promise.t(unit) =
  "registerIdentifiedUser";
[@bs.module "react-native-intercom"] [@bs.scope "default"]
external sendTokenToIntercom: {. "token": string} => Js.Promise.t(unit) =
  "sendTokenToIntercom";
[@bs.module "react-native-intercom"] [@bs.scope "default"]
external updateUser: attributes => Js.Promise.t(unit) = "updateUser";
[@bs.module "react-native-intercom"] [@bs.scope "default"]
external registerUnidentifiedUser: unit => Js.Promise.t(unit) =
  "registerUnidentifiedUser";
[@bs.module "react-native-intercom"] [@bs.scope "default"]
external logout: unit => Js.Promise.t(unit) = "logout";
[@bs.module "react-native-intercom"] [@bs.scope "default"]
external logEvent: logEvent => Js.Promise.t(unit) = "logEvent";

[@bs.module "react-native-intercom"] [@bs.scope "default"]
external displayMessenger: unit => Js.Promise.t(unit) = "displayMessenger";
[@bs.module "react-native-intercom"] [@bs.scope "default"]
external hideMessenger: unit => Js.Promise.t(unit) = "hideMessenger";
[@bs.module "react-native-intercom"] [@bs.scope "default"]
external handlePushMessage: unit => Js.Promise.t(unit) = "handlePushMessage";
[@bs.module "react-native-intercom"] [@bs.scope "default"]
external displayMessageComposer: unit => Js.Promise.t(unit) =
  "displayMessageComposer";
[@bs.module "react-native-intercom"] [@bs.scope "default"]
external displayMessageComposerWithInitialMessage:
  {. "message": string} => Js.Promise.t(unit) =
  "displayMessageComposerWithInitialMessage";
[@bs.module "react-native-intercom"] [@bs.scope "default"]
external displayConversationsList: unit => Js.Promise.t(unit) =
  "displayConversationsList";
[@bs.module "react-native-intercom"] [@bs.scope "default"]
external displayHelpCenter: unit => Js.Promise.t(unit) = "displayHelpCenter";

[@bs.module "react-native-intercom"] [@bs.scope "default"]
external getUnreadConversationCount: unit => Js.Promise.t(unit) =
  "getUnreadConversationCount";
[@bs.module "react-native-intercom"] [@bs.scope "default"]
external setLauncherVisibility: visibility => Js.Promise.t(unit) =
  "setLauncherVisibility";
[@bs.module "react-native-intercom"] [@bs.scope "default"]
external setInAppMessageVisibility: visibility => Js.Promise.t(unit) =
  "setInAppMessageVisibility";

[@bs.module "react-native-intercom"] [@bs.scope "default"]
external setupAPN: {. "deviceToken": string} => Js.Promise.t(unit) =
  "setupAPN";
[@bs.module "react-native-intercom"] [@bs.scope "default"]
external registerForPush: unit => Js.Promise.t(unit) = "registerForPush";
[@bs.module "react-native-intercom"] [@bs.scope "default"]
external setUserHash: {. "userHash": string} => Js.Promise.t(unit) =
  "setUserHash";
[@bs.module "react-native-intercom"] [@bs.scope "default"]
external setBottomPadding: {. "padding": string} => Js.Promise.t(unit) =
  "setBottomPadding";

module Notifications = {
  type t = {
    unreadCount: string,
    windowDidHide: string,
    windowDidShow: string,
  };
  [@bs.scope "Notifications"] [@bs.module "react-native-intercom"]
  external unreadCount: t = "UNREAD_COUNT";
  [@bs.scope "Notifications"] [@bs.module "react-native-intercom"]
  external windowDidHide: t = "WINDOW_DID_HIDE";
  [@bs.scope "Notifications"] [@bs.module "react-native-intercom"]
  external windowDidShow: t = "WINDOW_DID_SHOW";
};

type handler = int => unit;

[@bs.module "react-native-intercom"] [@bs.scope "default"]
external addEventListener: (Notifications.t, handler) => unit =
  "addEventListener";

[@bs.module "react-native-intercom"] [@bs.scope "default"]
external removeEventListener: (Notifications.t, handler) => unit =
  "removeEventListener";
