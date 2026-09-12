# C 语言学习记录

我的 C 语言和数据结构练习总仓库。后续练习统一上传到这里，按日期和项目名称分别存放，不再为每次练习单独创建仓库。

## 项目目录

| 目录 | 内容 |
| --- | --- |
| [2026.9.9-通讯录](./2026.9.9-通讯录/) | 动态顺序表通讯录：添加、删除、展示、查找、修改和菜单循环 |
| [2026.9.12-LeetCode88合并两个有序数组](./2026.9.12-LeetCode88合并两个有序数组/) | LeetCode 88：三指针从后往前合并两个有序数组 |

每个项目目录保留自己的源码和运行说明，编译时只编译该项目的源文件，不要把不同练习的 `main` 函数一起编译。

## 目录约定

```text
c-learning/
├── README.md
├── .gitignore
└── 2026.9.9-通讯录/
    ├── README.md
    ├── contact.h
    ├── contact.c
    ├── Seqlist.h
    ├── Seqlist.c
    └── test.c
```

后续项目使用“日期-项目名称”的目录名。仓库只存源码和必要说明，不上传 `.exe`、编译中间文件和 IDE 缓存。

## 学习记录

- [CSDN 通讯录学习复盘](https://blog.csdn.net/2601_95464512/article/details/164882007)
- [CSDN LeetCode 88 学习笔记](https://blog.csdn.net/2601_95464512/article/details/165127484)
- [Gitee 学习仓库](https://gitee.com/JJJax/jaxs-little-nest)

本仓库由原 `c-contact-manager` 改名整理而来，保留原提交历史。各练习是学习版本，具体功能和限制见项目内的 README。
