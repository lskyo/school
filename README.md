创建版本库
1.初始化一个Git仓库，使用git init命令。
2.添加文件到Git仓库，分两步：
第一步，使用命令git add <file>，注意，可反复多次使用，添加多个文件；
第二步，使用命令git commit -m "说明"，完成。
注意git config命令的--global参数，用了这个参数，表示你这台机器上所有的Git仓库都会使用这个配置，当然也可以对某个仓库指定不同的用户名和Email地址。




时光机穿梭
1、要随时掌握工作区的状态，使用git status命令。
2、如果git status告诉你有文件被修改过，用git diff可以查看修改内容。




版本回退
1、HEAD指向的版本就是当前版本，因此，Git允许我们在版本的历史之间穿梭，使用命令git reset --hard commit_id。
2、穿梭前，用git log <--pretty=oneline> 可以查看提交历史，以便确定要回退到哪个版本。
3、要重返未来，用git reflog查看命令历史，以便确定要回到未来的哪个版本。




撤销修改
场景1：当你改乱了工作区某个文件的内容，想直接丢弃工作区的修改时，用命令git checkout -- file。
场景2：当你不但改乱了工作区某个文件的内容，还添加到了暂存区时，想丢弃修改，分两步，第一步用命令git reset HEAD file，就回到了场景1，第二步按场景1操作。
场景3：已经提交了不合适的修改到版本库时，想要撤销本次提交，参考版本回退一节，不过前提是没有推送到远程库。




删除文件
命令git rm用于删除一个文件。如果一个文件已经被提交到版本库，那么你永远不用担心误删，但是要小心，你只能恢复文件到最新版本，你会丢失最近一次提交后你修改的内容。
命令git checkout -- filename 可以把误删的文件恢复到最新版本。




创建SSH密钥
$ ssh_keygen -t rsa -C "youremail@example.com"
成功后在/home/user/.ssh/下找到  id_rsa.pub (公钥) 和  id_rsa (私钥) 




添加远程库
1、要关联一个远程库，使用命令git remote add origin git@server-name:path/repo-name.git；
2、关联后，使用命令git push -u origin master第一次推送master分支的所有内容；
此后，每次本地提交后，只要有必要，就可以使用命令git push origin master推送最新修改；




从远程库克隆
要克隆一个仓库，首先必须知道仓库的地址，然后使用git clone命令克隆。
Git支持多种协议，包括https，但通过ssh支持的原生git协议速度最快。




创建和合并分支
查看分支：git branch
创建分支：git branch <name>
切换分支：git checkout <name>
创建+切换分支：git checkout -b <name>
合并某分支到当前分支：git merge <name>
删除分支：git branch -d <name>
强行删除分支：git branch -D <name>
用git log --graph命令可以看到分支合并图。




分支管理策略
在实际开发中，我们应该按照几个基本原则进行分支管理：
首先，master分支应该是非常稳定的，也就是仅用来发布新版本，平时不能在上面干活；
那在哪干活呢？干活都在dev分支上，也就是说，dev分支是不稳定的，到某个时候，比如1.0版本发布时，再把dev分支合并到master上，在master分支发布1.0版本；
你和你的小伙伴们每个人都在dev分支上干活，每个人都有自己的分支，时不时地往dev分支上合并就可以了。

准备合并dev分支，请注意--no-ff参数，表示禁用Fast forward，合并后的历史有分支，能看出来曾经做过合并，而fast forward合并就看不出来曾经做过合并。
$git merge --no-ff -m "merge with no-ff" dev




Bug分支
当手头工作没有完成时，先把工作现场git stash一下，然后去修复bug。
修复后，一是用git stash apply恢复，但是恢复后，stash内容并不删除，你需要用git stash drop来删除；
另一种方式是用git stash pop，恢复的同时把stash内容也删了：，回到工作现场。
多次stash可以用git stash list 查看内容。




多人协作
多人协作的工作模式通常是这样：
1.首先，可以试图用git push origin branch-name推送自己的修改；
2.如果推送失败，则因为远程分支比你的本地更新，需要先用git pull试图合并；
3.如果合并有冲突，则解决冲突，并在本地提交；
4.没有冲突或者解决掉冲突后，再用git push origin branch-name推送就能成功！
如果git pull提示“no tracking information”，则说明本地分支和远程分支的链接关系没有创建，
用命令git branch --set-upstream branch-name origin/branch-name建立本地分支和远程分支的关联。
要查看远程库的信息，用git remote <-v>
从本地推送分支，使用git push origin branch-name，如果推送失败，先用git pull抓取远程的新提交；
在本地创建和远程分支对应的分支，使用git checkout -b branch-name origin/branch-name，本地和远程分支的名称最好一致；




创建标签
命令git tag <name>用于新建一个标签，默认为HEAD，也可以指定一个commit id；
git tag -a <tagname> -m "blablabla..."可以指定标签信息；
git tag -s <tagname> -m "blablabla..."可以用PGP签名标签；
用git show <tagname>查看标签信息
命令git tag可以查看所有标签。




操作标签
命令git push origin <tagname>可以推送一个本地标签；
命令git push origin --tags可以推送全部未推送过的本地标签；
命令git tag -d <tagname>可以删除一个本地标签；
命令git push origin :refs/tags/<tagname>可以删除一个远程标签。




自定义Git
$git config --global alias.st status  把status用st代替
$git config --global alias.unstage ‘reset HEAD' 把reset HEAD用unstage代替
每个仓库的Git配置文件都放在.git/config文件中
当前用户的Git配置文件放在用户主目录下的一个隐藏文件.gitconfig中
让Git显示颜色，会让命令输出看起来更醒目：$ git config --global color.ui true
在Git工作区的根目录下创建一个特殊的.gitignore文件，然后把要忽略的文件名填进去，Git就会自动忽略这些文件。
https://github.com/github/gitignore 里已经为我们准备了各种配置文件。




搭建Git服务器
第一步，安装git：
$ sudo apt-get install git

第二步，创建一个git用户，用来运行git服务：
$ sudo adduser git

第三步，创建证书登录：
收集所有需要登录的用户的公钥，就是他们自己的id_rsa.pub文件，把所有公钥导入到/home/git/.ssh/authorized_keys文件里，一行一个。

第四步，初始化Git仓库：
先选定一个目录作为Git仓库，假定是/srv/sample.git，在/srv目录下输入命令：
$ sudo git init --bare sample.git
Git就会创建一个裸仓库，裸仓库没有工作区，因为服务器上的Git仓库纯粹是为了共享，所以不让用户直接登录到服务器上去改工作区，并且服务器上的Git仓库通常都以.git结尾。然后，把owner改为git：
$ sudo chown -R git:git sample.git

第五步，禁用shell登录：
出于安全考虑，第二步创建的git用户不允许登录shell，这可以通过编辑/etc/passwd文件完成。找到类似下面的一行：
git:x:1001:1001:,,,:/home/git:/bin/bash
改为：
git:x:1001:1001:,,,:/home/git:/usr/bin/git-shell
这样，git用户可以正常通过ssh使用git，但无法登录shell，因为我们为git用户指定的git-shell每次一登录就自动退出。

第六步，克隆远程仓库：
现在，可以通过git clone命令克隆远程仓库了，在各自的电脑上运行：
$ git clone git@server:/srv/sample.git

管理公钥
如果团队很小，把每个人的公钥收集起来放到服务器的/home/git/.ssh/authorized_keys文件里就是可行的。如果团队有几百号人，就没法这么玩了，这时，可以用Gitosis来管理公钥。






