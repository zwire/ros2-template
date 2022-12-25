# custom_component

C++でのライブラリファイルの作り方です。  
なかなか仕組みがややこしくてコピペでは作れないと思うので，コマンドで作成してからこのテンプレとの差分を埋める感じで作っていただけたらと思います。  
まずは以下のコマンドを打ちます。依存関係を後から付け足すのはめんどいので，ここでちゃんと書きましょう。  

```
cd <work_dir>/src && ros2 pkg create <pkg_name> --build-type ament_cmake --dependencies rclcpp rclcpp_components <other_deps> --library-name <node_name>
```

次に，自動生成される<node_name>.hppと<node_name>.cppを本リポジトリを参考に書き換えてください。  
ポイントは謎のおまじないマクロを何個か入れることと，引数違いのコンストラクタを2つ作ることですね。  

さらに，[CMakeLists.txt](CMakeLists.txt)を少しいじります。例に従って以下を追記してください。  

```
# add a postscript
rclcpp_components_register_node(
  <node_name>
  PLUGIN "<namespace::Class>"
  EXECUTABLE <preferred_name>
)
```

<node_name>はパッケージ作成時に決めたもの。<namespace::Class>も決まっています。サンプルではcustom_component::VehicleNodeです。  
<preferred_name>は実行方法3で使えるショートカット名です。呼びやすい名前をつけましょう。  
準備は以上です。ビルドしましょう。  

```
cd <work_dir> && colcon build
. install/local_setup.bash
```

ビルドできたら，次のコマンドで作成したcomponentが存在することを確認します。  

```
ros2 component types
```

作成したcomponentを実行する方法はいくつかあります。  

1. 共有ライブラリとして実行
普通にmain文を作って呼ぶ方法です。  
```
#include <rclcpp/rclcpp.hpp>
#include "custom_component/vehicle_node.hpp"

int main(int argc, char * argv[])
{
  rclcpp::init(argc,argv);
  rclcpp::spin(std::make_shared<custom_component::VehicleNode>());
  rclcpp::shutdown();
  return 0;
}
```

ただ，共有ライブラリとして呼ぶのは毎回簡素なmain文を書くので分ける意味がわからん，となります。  
そこで，main文用のパッケージを作らず単独で実行する以下のような方法があります。  

2. component単体実行
```
ros2 component standalone <pkg_name> <namespace::Class>
ex) ros2 component standalone custom_component custom_component::VehicleNode
```

これだと幾分マシですが，まだ長ったらしいです。  
単体で動かすならショートカットしましょう。先ほどCMakeLists.txtで設定した名前を使って次のようにします。  

3. 任意の名前で実行
```
ros2 run <pkg_name> <preferred_name>
ex) ros2 run custom_component vehicle
```

いいですね。  
さらに，componentの良いところはROSのnodeletに相当するメモリの共有，すなわち単一プロセスで複数nodeを動かせる点です。  
考え方としては，先にコンテナを立ち上げ，そこにcomponent化したnodeをloadする(放り込んでいく)感じです。  

4. ノードをコンテナにまとめて実行
```
ros2 run rclcpp_components component_container
# (マルチスレッドの場合は ros2 run rclcpp_components component_container_mt)

# other terminal
ros2 component load /ComponentManager <pkg_name> <namespace::ClassName>
ex) ros2 component load /ComponentManager custom_component custom_component::VehicleNode
```

このように，単一の実行ファイルとしても振る舞える(テストに便利！)，そしてプロセスに合流するライブラリとしても振る舞える点がROS2のcomponentの旨味のようですね。気持ちいいです。  

### その他
Python単体でライブラリ化することはない？かなと思いますが，一応C++のテンプレに混在させる方法はありました。  
* [Qiita - c++とpython共存パッケージのテンプレート](https://qiita.com/ousagi_sama/items/e1eb921f1b2e6b890133)

### 参考
* [ROS2のノードの書き方を理解](https://gbiggs.github.io/rosjp_ros2_intro/ros2_basics.html#ros-2%E3%81%AE%E3%83%8E%E3%83%BC%E3%83%89%E3%81%AE%E6%9B%B8%E3%81%8D%E6%96%B9%E3%82%92%E7%90%86%E8%A7%A3)
* [ROS2におけるコンポーネントの作成](https://qiita.com/NeK/items/775c0ddb4e10ed091068)
* [【ROS 2】シングルプロセスで複数のノードを構成する（公式文書和訳）](https://www.moriken254.com/entry/2019/05/07/220454)
