# arc2023

## user settings

OS側で必要となる作業は以下の通りです。

### user add

root ユーザで以下を実行します。

```
useradd arc -m -G sudo
passwd arc
```

## download ARC2023

arc ユーザで以下を実行します。

```
git clone https://github.com/acchi17/ARC2023.git ARC2023
cd ARC2023
chmod 700 SetupAutoStart.sh
sudo bash SetupAutoStart.sh
```
