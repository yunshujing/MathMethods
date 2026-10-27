# 数值计算方法实验

> C 语言实现的数值计算方法课程实验：插值、曲线拟合、数值积分、线性方程组。

![C](https://img.shields.io/badge/C-99-00599C?style=flat&logo=c&logoColor=white)
![status](https://img.shields.io/badge/status-coursework-lightgrey)

## 实验

| 目录 | 内容 | 入口 |
| --- | --- | --- |
| `work1/` | C 基础：字符串查找、数据统计 | `gcc work1/week1_1.c -o main && ./main` |
| `work2/` | 秦九韶算法、拉格朗日插值 | `gcc work2/lagrange.c -o lagrange -lm && ./lagrange` |
| `work3/` | 牛顿插值：差商/均差 | `gcc work3/newton_difference.c -o newton -lm && ./newton` |
| `work4/` | 最小二乘曲线拟合 | `gcc work4/leastSquaresFit.c -o fit -lm && ./fit` |
| `work5/` | 数值积分：梯形公式、辛普森公式 | `gcc work5/trapezoidal_rule.c -o integral -lm && ./integral` |
| `work6/` | 高斯消元 / 线性方程组 | `gcc work6/1.c -o gauss -lm && ./gauss` |

## 项目结构

```text
MathMethods/
├── work1/        # C 基础练习
├── work2/        # 秦九韶算法、拉格朗日插值
├── work3/        # 牛顿插值
├── work4/        # 最小二乘曲线拟合
├── work5/        # 梯形公式、辛普森公式
├── work6/        # 高斯消元 / 线性方程组
├── exe/          # 编译产物
└── readme.md     # 本文件
```

## 环境要求

- GCC（C99 或更高）
- 数学库 `libm`（链接时加 `-lm`）

## 编译与运行

```bash
gcc work2/lagrange.c -o lagrange -lm
./lagrange
```

各实验目录下的 `.doc` / `.docx` 为实验报告或题目说明，`.exe` 为已有编译产物。

## 技术栈 / 学习点

- C 语言、数组与指针
- 插值：拉格朗日插值、牛顿插值
- 曲线拟合：最小二乘法
- 数值积分：梯形公式、辛普森公式
- 线性方程组：高斯消元

## 说明

- 本仓库为数值计算方法课程作业，不是生产项目。
- `tempCodeRunnerFile.c` 和 `*.exe` 为本地运行/编译产物，可忽略。
