space_outliner.cc 初步文档:
在space_outliner模块中，outliner_select.cc负责处理Outliner区域中的选择操作。Outliner是Blender用户界面的一部分，它提供了一个树状视图，显示场景中的所有元素，如对象、材质、贴图等。

代码中定义了一系列的操作符（operator），这些操作符是Blender中执行特定任务的函数。这些操作符被绑定到UI事件（如鼠标点击或按键），并在需要时由用户触发。这些操作符包括：

OUTLINER_OT_item_activate: 当用户点击Outliner中的项目时激活这个项目。这可能涉及选择物体、展开/折叠树节点、切换属性编辑器的上下文等。
OUTLINER_OT_select_box: 当用户在Outliner中拖动鼠标形成选择框时执行。它可以选择或取消选择被框选的项目。
OUTLINER_OT_select_walk: 这允许用户通过键盘导航（上下左右）在Outliner中移动和选择项目。
每个操作符都有多个与之关联的函数：

invoke: 当操作首次被调用时执行，通常用于初始化操作或处理输入事件。
exec: 当操作需要执行其主要任务时被调用。
modal: 如果操作需要模态（持续的、交互的）输入，这个函数会被调用来管理状态。
poll: 这个函数决定操作是否可以在当前上下文中执行。
此外，操作符还定义了一些属性（例如，是否扩展选择或是否递归选择），这些属性可以在操作过程中读取和修改。

代码使用了几个辅助函数，例如：

outliner_flag_set: 设置或清除Outliner树中所有元素的标志（例如，选择标志）。
outliner_item_select: 处理单个Outliner项目的选择逻辑。
outliner_find_item_at_y: 在Outliner的垂直坐标处查找项目。
outliner_box_select: 处理框选逻辑，选择或取消选择在给定矩形框内的所有项目。
最后，代码依赖于Blender的内部API和数据结构来管理场景数据、事件处理和UI反馈。