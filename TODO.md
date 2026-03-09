# TODO - comp5533_GAS

## 已完成

- [x] 创建 UE5.6 C++ 项目。
- [x] 启用 `GameplayAbilities` 插件并在模块中接入 GAS 依赖。
- [x] 接入 `EnhancedInput` 模块。
- [x] 创建 `ABaseCharacter` C++ 基类骨架。
- [x] 创建基础蓝图角色：`BP_BaseMyBaseCharacter`、`BP_Player`、`BP_Enemy`。
- [x] 导入首批能力、UI、FX、角色资源（含 Paragon Shinbi 资源）。
- [x] 配置默认启动地图 `/Game/GAS`。

## 待确认项（优先处理）

- [ ] 校验并修正默认 GameMode 路径（当前配置可能指向不存在的 `BP_GameMode` 资源）。
- [ ] 明确主测试地图（`/Game/GAS` 与 `/Game/Map/GAS` 仅保留一个主入口）。
- [ ] 检查导入资源依赖是否完整（材质、骨骼、贴图引用无丢失）。

## P0 - GAS 基础框架（高优先）

- [ ] 在 `ABaseCharacter` 中接入 `UAbilitySystemComponent`。
- [ ] 新建基础 `UAttributeSet`（Health、MaxHealth、Mana、MaxMana、AttackPower）。
- [ ] 实现属性初始化流程（默认值、回写、Clamp）。
- [ ] 抽离玩家/敌人角色基类（如 `APlayerCharacter`、`AEnemyCharacter`），避免所有逻辑堆在一个类。

## P1 - 技能与输入打通

- [ ] 建立 Enhanced Input 到 GAS 的输入映射（InputAction -> GameplayTag -> Ability）。
- [ ] 新建基础能力类（如 `UGameplayAbility` 子类基类）。
- [ ] 先落地 1~2 个能力闭环（推荐 `Dash` + `FireBlast`）：
- [ ] 能力激活与结束。
- [ ] 资源消耗（Mana/体力等）。
- [ ] 冷却管理与 UI 可见状态。

## P2 - GameplayEffect 与战斗规则

- [ ] 创建基础 GE：`GE_Damage`、`GE_Heal`、`GE_Cooldown`。
- [ ] 搭建基础伤害计算流程（可先用简单系数，后续再扩展 ExecutionCalculation）。
- [ ] 处理受击、死亡、复活或重置流程。
- [ ] 用 GameplayTags 管理角色状态（如 `State.Dead`、`State.Stunned`、`State.Casting`）。

## P3 - 蓝图与表现层接入

- [ ] 将已导入的技能特效资源绑定到实际能力释放节点。
- [ ] 将 UI 图标资源绑定技能栏和冷却显示。
- [ ] 搭建最小可玩 Demo 场景（玩家 + 敌人 + 技能交互）。
- [ ] 整理资源命名规范（前缀、目录、用途）并统一重命名。

## P4 - 稳定性与联机（可后置）

- [ ] 验证关键属性同步（多人 PIE）。
- [ ] 验证技能激活、冷却、伤害的网络一致性。
- [ ] 加入最小化日志与调试工具（Ability 激活日志、Tag 状态日志）。

## 里程碑验收

- [ ] M1：玩家可稳定释放 2 个能力，CD/消耗正确，UI 可展示。
- [ ] M2：玩家与敌人可互相造成伤害并触发死亡流程。
- [ ] M3：多人 PIE 下核心能力与属性同步正确。
