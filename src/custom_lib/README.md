# custom_lib

C++でのライブラリファイルの作り方です。  
テンプレとしてはほぼそのまま使えると思います。  
自分で作成したファイルと依存関係に従って適宜package.xmlとCMakeLists.txtを書き換えていただけたら，と思います。  
以下のinstallでヘッダとライブラリが生成される手筈です。  

```
install(
  DIRECTORY include/ 
  DESTINATION include
)
install(
  TARGETS lib
  EXPORT export_${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
)
```

Python単体でライブラリ化することはない？かなと思いますが，一応C++のテンプレに混在させる方法はありました。  
* [Qiita - c++とpython共存パッケージのテンプレート](https://qiita.com/ousagi_sama/items/e1eb921f1b2e6b890133)
