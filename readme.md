#  简介

 vs2019 + PCRE 8.44 在 Windows 10 下编译，工程文件就在目录下，直接下git编译就行，以下简单教程在网上抄的，感谢原作者。
 Privoxy 是一个 代理软件，有着先进的过滤能力和保护隐私的代理工具，它可以过滤网页内容，管理cookies，控制访问，除广告、横幅、弹出窗口等等，它同时支持单系统和多用户网络。
 结合 Tor 使用，可以完全匿踪，是白帽们的最爱。

# 配置浏览器

Privoxy 在启动后，默认运行在 localhost:8118 上。所以我们只要将浏览器的代理指向它即可。

配置完浏览器后，在浏览器中打开 http://p.p 网址，看是否显示如下内容：

This is Privoxy 3.0.26 on localhost (127.0.0.1), port 8118, enabled

如果有，说明 Privoxy 启动成功，且浏览器配置正确 - 此时，浏览器所有的流量都会经过 Privoxy 代理。

# 设置 Privoxy
在启动 Privoxy、配置浏览器完成后，可以开始定制我们的 Privoxy 了。

从核心配置文件 config 说起。

config 文件在各种系统下位置、名称可能并不一样，比如 Windows 系统下，它其实叫 config.txt，在 openSUSE 系统下，它所在的目录为 /etc/privoxy，这个目录是个软链接，指向 /var/lib/privoxy/etc。

不过，通常情况下，我们不需要修改 config 文件。

通常，我们会修改另外两类文件：

- action 类文件

match-all.action
default.action
user.action

- filter 类文件

default.filter
user.filter
match-all.action、default.action、default.filter 这几个文件，建议不要修改，因为 Privoxy 升级时会覆盖掉。我们要把自定义的配置内容写入 user.action 或 user.filter。

## action 文件

顾名思义，action 文件定义 Privoxy 的动作，比如，我们在 user.action 文件中添加 {+block}：

{+block{禁止访问陈三的博客}}
.zfanw.com
分析一下：

{+block} 是一个动作，block后的 {} 写的是注释，可写可不写。
.zfanw.com 是上述动作的一个作用对象，分两个部分，一个 host，一个 path，host 部分支持部分通配符，比如 *、?、[0-9]、[a-z]；path 部分是指第一个 / 后的部分网址，支持 POSIX 1003.2 正则表达式，比 host 部分灵活。具体见actions 文档。
这样，Privoxy 就把我的网站拦下了：凡是 zfanw.com 的请求，均会返回 403，内容大概如下：

The proxy server is refusing connections

那么，说了这么多，user.action 文件在哪修改？修改后是否需要重启 Privoxy？

在配置过 Privoxy 的浏览器访问 http://config.privoxy.org/show-status，就可以看到所有配置文件的路径。默认情况下，我们只能查看配置，但其实可以启用编辑功能。通常我是直接用 Vim 来编辑。编辑完保存就能看到效果，无需重启 Privoxy。

## filter 文件

filter 文件定义过滤响应的规则，比如：

FILTER: replaceText 替换文本
s|陈三|陈四|g
第一行中，大写的 FILTER 表示定义一条过滤规则，replaceText 表示规则名称，再后面是注释。

第二行，对返回的页面进行修改。比如你用过 Vi/Vim 或 sed 等工具，应该对 s 这个替换命令很熟悉。简单说，上面的语句就是把页面内的代码作过更换 - Privoxy 去广告的原理正在于这里。

但是，user.filter 中只是定义过滤的规则，规则的应用，还是要在 action 文件中，所以在 user.action 文件中，加入如下配置：

{+filter{replaceText}}
.zfanw.com
我猜想你已经知道上面的配置的意思：filter 是指令，要求执行 user.filter 中定义的 replaceText，.zfanw.com 则定义 filter 的作用对象 - 即网址。

可是在试验中你可能发现，上面的 FILTER 规则并没有生效。

不不不，这当然不是作者在恶搞。这是因为，我的网站已经启用 https，而 Privoxy 对 https 加密的页面能做的极少 - 唯一的例外，就是前面生效的 {+block}。那是因为 https 请求的域名部分仍暴露给 Privoxy，所以才有办法拦截。

这意味着，在未来 https 越来越盛行的趋势下，Privoxy 的需求会越来越小。拿百度来说，现在它已经全线启用 https，曾经能够屏蔽百度页面内广告的 Privoxy，现在已无能为力。

# 代理转发

目前的主流浏览器都只支持 http 代理，是的，连 https 代理都不支持，更别提什么 socks 代理。

现在假定你本地启动了一个 socks 代理，运行在 127.0.0.1:9999，想让浏览器使用。怎么办？

一个办法，是借助 Privoxy 转发。

打开 Privoxy 的 config 文件，加入如下内容：

forward-socks5 / 127.0.0.1:9999 .
这样，所有经由 Privoxy 代理的流量均会被转发到本地 socks5 代理。

当然，你也可以根据域名来分流，比如 Google 的网站要转发给 sock5 代理，国内的网站不需要，则只要转发 Google 的域名即可：

forward-socks5 .google.com 127.0.0.1:9999 .
forward-socks5 google.com 127.0.0.1:9999 .
