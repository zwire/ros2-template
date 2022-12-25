# custom_component

C++でのライブラリファイルの作り方です。  
仕組みが

```
ros2 component types
```

```
ros2 component standalone custom_component custom_component::VehicleNode
```

```
ros2 run <pkg_name> <name>
```

```
# terminal1
ros2 run rclcpp_components component_container
# terminal2
ros2 component load /ComponentManager <pkg_name> <namespace::ClassName>
```

Python単体でライブラリ化することはない？かなと思いますが，一応C++のテンプレに混在させる方法はありました。  
* [Qiita - c++とpython共存パッケージのテンプレート](https://qiita.com/ousagi_sama/items/e1eb921f1b2e6b890133)

### 参考
* [ROS2のノードの書き方を理解](https://gbiggs.github.io/rosjp_ros2_intro/ros2_basics.html#ros-2%E3%81%AE%E3%83%8E%E3%83%BC%E3%83%89%E3%81%AE%E6%9B%B8%E3%81%8D%E6%96%B9%E3%82%92%E7%90%86%E8%A7%A3)
* [ROS2におけるコンポーネントの作成](https://qiita.com/NeK/items/775c0ddb4e10ed091068)
* [【ROS 2】シングルプロセスで複数のノードを構成する（公式文書和訳）](https://www.moriken254.com/entry/2019/05/07/220454)
