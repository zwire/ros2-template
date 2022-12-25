# custom_target

custom_msgsとcustom_libができたら，もう説明することはありません。  
nodeをクラス化できていれば，以下の方法でそれを立てることができます。  

```
rclcpp::init(argc, argv);
rclcpp::spin(std::make_shared<VehicleNode>());
rclcpp::shutdown();
```

node作ってmainも書いて二度手間と思いますが，オブジェクト指向プログラミングや後々component化することも考慮すると公式的にはこれが推奨される形式美であるようです。  
