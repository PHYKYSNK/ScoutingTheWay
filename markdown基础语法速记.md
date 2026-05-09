# Markdown 基础语法速记

> 常用写法备忘（GitHub / VS Code 预览通用；部分为 **GFM**，即 GitHub Flavored Markdown）。

---

## 标题

```markdown
# 一级标题
## 二级标题
### 三级标题
```

---

## 强调

```markdown
**粗体**  __粗体__
*斜体*    _斜体_
***粗斜体***
~~删除线~~
```

---

## 行内代码与代码块

````markdown
行内：`代码`

```java
//  fenced code block（三个反引号后写语言名，如 java）
public class Main {
    public static void main(String[] args) {}
}
```
````

**行内反引号**：若代码里本身有 `` ` ``，用 **双反引号** 包起来：`` `like_this` ``。

---

## 链接与图片

```markdown
[链接文字](https://example.com)
[带标题的链接](https://example.com "鼠标悬停提示")

![替代文字](图片路径或URL.png)
```

**引用式（可选）**：

```markdown
[链接文字][id]

[id]: https://example.com "可选标题"
```

---

## 列表

**无序**：

```markdown
- 项目
- 项目
  - 子项
* 也行
```

**有序**：

```markdown
1. 第一步
2. 第二步
   1. 子步骤
```

---

## 引用

```markdown
> 一行引用
> > 嵌套引用
```

---

## 分隔线

```markdown
---
***
___
```

---

## 表格（GFM）

```markdown
| 列 A | 列 B |
| --- | --- |
| 左对齐默认 | 内容 |
```

对齐（可选）：

```markdown
| 左 | 中 | 右 |
| :--- | :---: | ---: |
| a | b | c |
```

---

## 任务列表（GFM）

```markdown
- [ ] 未完成
- [x] 已完成
```

---

## 换行小技巧

- **同一段里硬换行**：行尾加 **两个空格** 再回车；或中间空一行变成新段落。
- **中文排版**：段落之间空一行，阅读更清晰。

---

## 转义

需要显示 `*`、`#`、`` ` `` 等符号本身时，前面加 `\`，例如：`\*` `\#`。
