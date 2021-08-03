
1.配置用户信息
git config --global user.name <你的用户名>
git config --global user.email <你的邮箱地址>

2.创建一个新仓库
git init

3.从远程服务器克隆一个仓库
git clone <远程仓库的 url>

4.现实当前的工作目录下的提交文件状态
(类似于 gitkraken 中右方窗口显示的信息)
git status

5.将指定文件Stage(标记为将要被提交的文件)
git add <文件路径>

6.将指定文件Unstage(取消标记为将要被提交的文件)
git reset <文件路径>

7.创建一个提交并提供信息
git commit -m "提交信息"

8.显示提交历史
(类似于Gitkraken中间窗口中显示提交信息)
git log

9.向远程仓库推送 Push
git push

10.从远程仓库拉取 Pull
git pull


**高阶操作

1.修改Amend上的一个提交
git commit --amend -m "<新提交信息>"

2.查看所有分支
git branch

3.创建新分支
git branch <分支名字>

4.切换分支
git branch -m <旧名字> <新名字>

5.删除分支
git branch -d <分支名字>

6.将分支变基(rebase)到master
    注：需要先切换到分支之后，再完成变基
    git checkout <分支名字>
    git rebase master

7.使用快进(fast-forward)将分支合并到master
git checkout <分支名字>
git merge --ff-only master

8.中止这一次提交的合并(当遇到冲突时)
git merge --about

9.将未提交的修改暂存(Stash)
git stash save "<可以输入一个信息>"

10.将上一个暂存的修改回复并从暂存列表中删除
git stash pop

11.牵出制定的提交
git checkout <提交的hash>

12.撤销旧提交
注：revert并不会修改旧提交历史，而是在工作书中生成与之前提交完全相反的修改
git revert <旧提交的hash>

13.利用reflog查看本地仓库中的所有操作
git reflog
