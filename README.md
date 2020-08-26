# `@reason-react-native/react-native-intercom`

[![Build Status](https://github.com/reason-react-native/intercom/workflows/Build/badge.svg)](https://github.com/reason-react-native/intercom/actions)
[![Version](https://img.shields.io/npm/v/@reason-react-native/react-native-intercom.svg)](https://www.npmjs.com/@reason-react-native/react-native-intercom)
[![Chat](https://img.shields.io/discord/235176658175262720.svg?logo=discord&colorb=blue)](https://reason-react-native.github.io/discord/)

[ReasonML](https://reasonml.github.io) /
[BuckleScript](https://bucklescript.github.io) bindings for
[`@react-native-community/intercom`](https://github.com/react-native-community/react-native-intercom).

Exposed as `ReactNativeIntercom` module.

`@reason-react-native/react-native-intercom` X.y._ means it's compatible with
`@react-native-community/intercom` X.y._

## Installation

When
[`@react-native-community/intercom`](https://github.com/react-native-community/react-native-intercom)
is properly installed & configured by following their installation instructions,
you can install the bindings:

```console
npm install @reason-react-native/react-native-intercom
# or
yarn add @reason-react-native/react-native-intercom
```

`@reason-react-native/react-native-intercom` should be added to
`bs-dependencies` in your `bsconfig.json`. Something like

```diff
{
  //...
  "bs-dependencies": [
    "reason-react",
    "reason-react-native",
    // ...
+    "@reason-react-native/react-native-intercom"
  ],
  //...
}
```

## Usage

### Types

#### `ReactNativeIntercom.t`

...

### Methods

#### `ReactNativeIntercom.registerIdentifiedUser`

```reason
let email = "user@example.com"
registerIdentifiedUser({"email": email);
```

### Example

```reason
[@react.component]
let make = () => {

  let (unread, setUnread) = React.useState(() => 0);

  React.useEffect0(() => {
    let onUnreadChange = count => setUnread(_ => count);
    Intercom.addEventListener(
      Intercom.Notifications.unreadCount,
      onUnreadChange,
    );
    Some(
      () =>
        Intercom.removeEventListener(
          Intercom.Notifications.unreadCount,
          onUnreadChange,
        ),
    );
  });
```

---

## Changelog

Check the [changelog](./CHANGELOG.md) for more informations about recent
releases.

---

## Contribute

Read the
[contribution guidelines](https://github.com/reason-react-native/.github/blob/master/CONTRIBUTING.md)
before contributing.

## Code of Conduct

We want this community to be friendly and respectful to each other. Please read
[our full code of conduct](https://github.com/reason-react-native/.github/blob/master/CODE_OF_CONDUCT.md)
so that you can understand what actions will and will not be tolerated.
