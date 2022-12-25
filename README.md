# ros2-template

階層構造とCMakeLists.txtの書き方をわかりやすくテンプレ化するために作成したリポジトリです。  
ROS2のお約束としてワークスペース内の階層構造は以下のようになります。

```
<work_dir>
 - src
  - <package1>
   - CMakeLists.txt (auto generated)
   - package.xml (auto generated)
   - src (auto generated)
    - <node1>.cpp
  - <package2>
   - ...
  - <package3>
   - ...
```

また，ワークスペース内での参照をうまくやるためにmsg, lib, targetのパッケージは分けることが推奨されています。  

* msgにはコードを書かず型情報だけを持たせます。  
* libにはnodeクラスを記述します。component(ROSで言うnodelet)にすることもできる，という狙いがあります。
* targetはいわゆる実行ファイルです。ROS2ならではのシンプルな書き方があります。  

各フォルダのREADMEにも説明を加えています。  

### 参考
* [Zenn - Uchida Ryo](https://zenn.dev/uchidaryo)
* [Qiita - ROS2導入&レクチャー](https://qiita.com/NeK/items/7ac0f4ec10d51dbca084)
