# custom_msgs
  
独自のメッセージ型を記述するパッケージのテンプレです。  
パッケージ名には---.msgみたいな感じで名前付けして，メッセージならmsg，サービスならsrv，アクションならactionというフォルダを作り記述するだけです。
 
他のファイルはほとんどデフォルトのままですが，メッセージ型を生成するためにpackage.xmlに
 
```
<build_depend>rosidl_default_generators</build_depend>
<exec_depend>rosidl_default_runtime</exec_depend>
<member_of_group>rosidl_interface_packages</member_of_group>
```
  
を，さらにCMakeLists.txtに  
  
```
foreach(dep IN LISTS MSGS)
 list(APPEND MSG_FILES msg/${dep}.msg)
endforeach()
rosidl_generate_interfaces(
 ${PROJECT_NAME} ${MSG_FILES}
 DEPENDENCIES ${DEPS}
)
ament_export_dependencies(rosidl_default_runtime)
```
  
を書き加える必要があります。
