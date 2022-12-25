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

また，ワークスペース内での参照をうまくやるためにmsg, componentのパッケージは分けることが推奨されています。  

* msgにはコードを書かず型情報だけを持たせます。  
* componentにはnodeクラスを記述します。node単体の実行することも，ライブラリとしてまとめて単一プロセスに合流させること(ROSで言うnodelet)もできる優秀なやつで，これがROS2の推しどころかな？と個人的に思います。  

各フォルダのREADMEに詳しい説明を加えています。  

### 参考
* [Zenn - Uchida Ryo](https://zenn.dev/uchidaryo)
* [Qiita - ROS2導入&レクチャー](https://qiita.com/NeK/items/7ac0f4ec10d51dbca084)
