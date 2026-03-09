# comp5533_GAS

基于 Unreal Engine 5.6 的 GAS（Gameplay Ability System）练习项目。

## 当前进展（2026-03-09）

- 已创建 UE5 C++ 项目并启用 `GameplayAbilities` 插件。
- `Build.cs` 已加入 GAS 相关模块：
  - `GameplayAbilities`
  - `GameplayTags`
  - `GameplayTasks`
- 输入体系已接入 `EnhancedInput` 模块（代码依赖和输入配置已存在）。
- 已创建 C++ 基类：
  - `ABaseCharacter`（当前为基础骨架，尚未接入 ASC/属性/能力逻辑）
- 已创建基础蓝图角色资源：
  - `/Game/BP/BP_BaseMyBaseCharacter`
  - `/Game/BP/Character/BP_Player`
  - `/Game/BP/Character/BP_Enemy`
- 已导入一批能力/UI/角色相关资源（用于后续技能与表现接入）：
  - `/Game/Assets/Abilities/*`（FireBlast、GroundBlast、HealthRegen、Laser）
  - `/Game/Assets/UI/*`
  - `/Game/Assets/FX/*`
  - `/Game/ParagonShinbi/*`
- 默认地图设置为：
  - `GameDefaultMap=/Game/GAS`
  - `EditorStartupMap=/Game/GAS`

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

## 已知注意点

- `DefaultEngine.ini` 中 `GlobalDefaultGameMode` 指向 `/Game/BP/Gameplay/BP_GameMode.BP_GameMode_C`，当前目录下尚未发现对应资源，后续需补齐或改为已有 GameMode。
- 目前能力系统主体逻辑（ASC、AttributeSet、GA/GE）尚未落地，仍处于项目骨架阶段。

## 下一步

详细开发计划见 `TODO.md`。
