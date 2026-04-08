# comp5533_GAS

基于 Unreal Engine 5.6 的 GAS（Gameplay Ability System）练习项目。

## 环境要求

- Unreal Engine `5.6`
- Visual Studio 2022（含 C++ 开发工具链）

## 如何打开项目

1. 用 UE 5.6 打开 `comp5533_GAS.uproject`。
2. 首次打开如提示编译 C++ 模块，选择 Yes。
3. 进入编辑器后默认会打开 `/Game/GAS`。
4. Play 运行当前测试场景。

## 目录说明

- `Source/comp5533_GAS/`
  - 项目 C++ 代码（当前主要是 `ABaseCharacter` 基类）
- `Config/`
  - 项目配置（地图、渲染、输入等）
- `Content/BP/`
  - 角色蓝图与玩法蓝图资源
- `Content/Assets/`
  - 技能、UI、FX 资源
- `Content/ParagonShinbi/`
  - 导入的 Paragon Shinbi 相关资源

