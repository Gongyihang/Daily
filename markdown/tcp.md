**编者前言：**
本文近9千文字，预计阅读时间15分钟，文章内容整理于网络，仅供分享，更多好文请关注**公众号：一航代码**

公众号阅读链接：[TCP是什么？为什么要三次握手四次挥手？     （本文近9千字，建议收藏）](https://mp.weixin.qq.com/s/pqt0_PUPwE-4pWanAd3mlA)

**一. 基本描述**

**1.TCP是什么？**

**&emsp;定义：传输控制协议（TCP，Transmission Control Protocol）** 是一种**面向连接的**、**可靠的**、**基于字节流**的**传输层**通信协议，由IETF的RFC 793定义。

**2.为什么要定义TCP协议？**

&emsp;互联网络与单个网络有很大的不同，因为互联网络的不同部分可能有截然不同的**拓扑结构、带宽、延迟、数据包大小**和其他参数。TCP的设计目标是能够动态地适应互联网络的这些特性，而且具备面对各种故障时的健壮性。

&emsp;不同主机的应用层之间经常需要可靠的、像管道一样的连接，但是IP层不提供这样的流机制，而是提供不可靠的**包交换**。

&emsp;TCP协议是为了**在不可靠的互联网络上提供可靠的端到端字节流**而专门设计的一个传输协议。

**3.数据流和数据包有什么区别？**
 &emsp;**数据流（data stream）**，最初是通信领域使用的概念，代表传输中所使用的信息的数字编码信号序列。然而，我们所提到的数据流概念与此不同。这个概念最初在1998年由Henzinger在文献87中提出，他将数据流定义为 **“只能以事先规定好的顺序被读取一次的数据的一个序列”**
&emsp;**数据包（data package）**，在包交换网络里，单个消息被划分为多个数据块，这些数据块称为数据包，它包含发送者和接收者的地址信息。这些包然后沿着不同的路径在一个或多个网络中传输，并且在目的地重新组合。理论上是一次收完所有数据并还回给应用层。 
**&emsp;数据流可以分成多个有序的数据包。** 流的特点并不是一次收完所有数据，比如，30个字节，第一次可能是收到6个，第二次3个，第三次11个。

**二. 主要功能**
&emsp;应用层向TCP层发送用于网间传输的、用**8位字节**表示的**数据流**，TCP则把数据流分割成适当长度的报文段（**最大传输段大小（MSS**）通常受该计算机连接的网络的数据链路层的最大传送单元（MTU）限制）。之后TCP把**数据包**传给IP层，由它来通过网络将包传送给接收端实体的TCP层。
&emsp;TCP为了**保证不发生丢包**，就给每个包一个**序号**，同时序号也保证了传送到接收端实体的包的按序接收。然后接收端实体对已成功收到的包发回一个相应的**确认（ACK）**；如果发送端实体在合理的往返时延（RTT）内未收到确认，那么对应的数据包就被假设为已丢失将会被进行**重传**。
&emsp;TCP用一个校验和函数来检验数据是否有错误；在发送和接收时都要计算校验和。

- 在数据**正确性**与**合法性**上，TCP用一个校验和函数来检验数据是否有错误，在**发送**和**接收**时都要计算校验和；同时可以使用md5认证对数据进行加密。
- 在保证**可靠性**上，采用超时重传和捎带确认机制。
- 在流量控制上，采用**滑动窗口协议**，协议中规定，对于窗口内未经确认的分组需要重传。
- 在拥塞控制上，采用广受好评的TCP**拥塞控制算法**（也称AIMD算法）。

**三. 主要特点**
&emsp;TCP是一种面向广域网的通信协议，目的是在跨越多个网络通信时，为两个通信端点之间提供一条具有下列特点的通信方式：

**（1）基于流的方式；
（2）面向连接；
（3）可靠通信方式；
（4）在网络状况不佳的时候尽量降低系统由于重传带来的带宽开销；
（5）通信连接维护是面向通信的两个端点的，而不考虑中间网段和节点。**

为满足TCP协议的这些特点，TCP协议做了如下的规定：
①**数据分片**：在发送端对用户数据进行分片，在接收端进行重组，由TCP确定分片的大小并控制分片和重组；

②**到达确认**：接收端接收到分片数据时，根据分片数据序号向发送端发送一个确认；

③**超时重发**：发送方在发送分片时启动超时定时器，如果在定时器超时之后没有收到相应的确认，重发分片；

④**滑动窗口**：TCP连接每一方的接收缓冲空间大小都固定，接收端只允许另一端发送接收端缓冲区所能接纳的数据，TCP在滑动窗口的基础上提供流量控制，防止较快主机致使较慢主机的缓冲区溢出；

⑤**失序处理**：作为IP数据报来传输的TCP分片到达时可能会失序，TCP将对收到的数据进行重新排序，将收到的数据以正确的顺序交给应用层；

⑥**重复处理**：作为IP数据报来传输的TCP分片会发生重复，TCP的接收端必须丢弃重复的数据；

⑦**数据校验**：TCP将保持它首部和数据的检验和，这是一个端到端的检验和，目的是检测数据在传输过程中的任何变化。如果收到分片的检验和有差错，TCP将丢弃这个分片，并不确认收到此报文段导致对端超时并重发。

**四. TCP报文段的首部格式**
![报文](https://img-blog.csdnimg.cn/20200411103101962.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0dvbmdfWWloYW5n,size_16,color_FFFFFF,t_70#pic_center)
![TCP报文](https://img-blog.csdnimg.cn/20200411103148249.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0dvbmdfWWloYW5n,size_16,color_FFFFFF,t_70#pic_center)
**&emsp;源端口（Source Port）**：占2个字节。
**&emsp;目的端口（Destination Port）**：占2个字节。
**&emsp;序号（Sequence Number）seq**：占4个字节，用来标记数据段的顺序，TCP把连接中发送的所有数据字节都编上一个序号，第一个字节的编号由本地随机产生；给字节编上序号后，就给每一个报文段指派一个序号；序列号seq就是这个报文段中的第一个字节的数据编号。
**&emsp;确认号（Acknowledgment Number）ack**：占4个字节，期待收到对方下一个报文段的第一个数据字节的序号；序列号表示报文段携带数据的第一个字节的编号；而确认号指的是期望接收到下一个字节的编号；因此当前报文段最后一个字节的编号+1即为确认号。
**&emsp;数据偏移（Data Offset）**：占4位，该字段的值是TCP首部（包括选项）长度除以4。
**&emsp;保留(Reserved)**：占4位，这些位必须是0。为了将来定义新的用途所保留，其中RFC3540将Reserved字段中的最后一位定义为Nonce标志。
**&emsp;6个标志位：**
**&emsp;紧急指针（URG）**：占1位，仅当URG=1时，紧急指针字段才有效。
**&emsp;确认（ACK）**：占1位，仅当ACK=1时，确认号字段才有效。ACK=0时，确认号无效。
**&emsp;Push功能（PSH）**：占1位，仅当PSH=1时，表示这个包是带数据的，发送端告诉接收端，这个数据包以及以前接收到的数据包需要交给应用层立即进行处理。
**&emsp;复位（RST）**：占1位，仅当RST=1时，用于复位因某种原因引起出现的错误连接，也用来拒绝非法数据和请求。如果接收到RST位时候，通常发生了某些错误。
**&emsp;同步（SYN）**：占1位，连接建立时用于同步序号。当SYN=1，ACK=0时表示：这是一个连接请求报文段。若同意连接，则在响应报文段中使得SYN=1，ACK=1。因此，SYN=1表示这是一个连接请求，或连接接受报文。SYN这个标志位只有在TCP建产连接时才会被置1，握手完成后SYN标志位被置0。
**&emsp;终止（FIN）**：占1位，用来释放一个连接。FIN=1表示：此报文段的发送方的数据已经发送完毕，并要求释放运输连接。
**&emsp;窗口（Windows）**：占2个字节，表示接收缓冲区的空闲空间，用来告诉TCP连接对端自己能够接收的最大数据长度。
**&emsp;校验和（Checksum）**：占2个字节，目的是为了发现TCP首部和数据在发送端到接收端之间发生的任何改动。如果接收方检测到检验和有差错，则TCP段会被直接丢弃。
**&emsp;紧急指针（Urgent  Pointer）**：占2个字节，在URG标志设置了时才有效。与序号字段的值相加后表示最后一个紧急数据的下一字节的序号，可以说这个字段是紧急指针相对当前序号的偏移。
**&emsp;选项部分（Options）**：长度不定，最长报文大小，接收方或发送方所能接受的最大报文段的长度。通常连接方都在通信的第一个报文段中指明这个选项，但长度必须以是32bits的整数倍。常见的选项包括MSS、SACK、Timestamp等等。
**&emsp;填充（Padding）**：顾名思义，选项部分如果不是32位的整数倍，要添加填充位，加入额外的零，保证TCP头是32的整数倍。
**&emsp;数据部分（Data）**： TCP 报文段中的数据部分是可选的。在一个连接建立和一个连接终止时，双方交换的报文段仅有 TCP 首部。如果一方没有数据要发送，也使用没有任何数据的首部来确认收到的数据。在处理超时的许多情况中，也会发送不带任何数据的报文段。、

**&emsp;一个完整的TCP首部展示：**
![TCP首部报文示例](https://img-blog.csdnimg.cn/20200411103356290.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0dvbmdfWWloYW5n,size_16,color_FFFFFF,t_70#pic_center)
**五. 工作方式**
- **建立连接-三次握手：**

&emsp;TCP是因特网中的传输层协议，使用三次握手协议建立连接。当主动方发出SYN连接请求后，等待对方回答SYN+ACK，并最终对对方的 SYN 执行 ACK 确认。这种建立连接的方法可以防止产生错误的连接，TCP使用的流量控制协议是可变大小的滑动窗口协议。
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200411103640506.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0dvbmdfWWloYW5n,size_16,color_FFFFFF,t_70#pic_center)
**&emsp;TCP三次握手的过程如下：**

&emsp;1. 客户端发送SYN（seq=x）报文，给服务器端，进入SYN_SEND状态。（该数据包中，**初始序列号（ISN）** 是客户端随机产生的一个值，即x，确认号ACK=0；）

&emsp;2. 服务器端收到SYN报文，回应一个SYN （seq=y）ACK（ACK=x+1）报文，进入SYN_RECV状态。（该数据包中，**初始序列号（ISN）** 是服务器随机产生的一个值，即y，确认号ACK是客户端的初始序列号加上1，即x+1）

&emsp;3. 客户端收到服务器端的SYN报文，回应一个ACK（ACK=y+1）报文，进入Established状态。（该数据包中，序列号是上一个同步请求数据包中的确认号值加上1，即x+1，确认号是服务器的初始序列号加上1，即y+1。）

&emsp;三次握手完成，TCP客户端和服务器端成功地建立连接，可以开始传输数据了。
![三次握手](https://img-blog.csdnimg.cn/20200411103706523.gif#pic_center)
![三次和四次](https://img-blog.csdnimg.cn/20200411103851826.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0dvbmdfWWloYW5n,size_16,color_FFFFFF,t_70#pic_center)
**连接终止-四次挥手：**

&emsp; 建立一个连接需要三次握手，而终止一个连接要经过四次握手，这是由TCP的半关闭（half-close）造成的。具体过程如下图所示。 
![四次挥手](https://img-blog.csdnimg.cn/20200411103925844.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0dvbmdfWWloYW5n,size_16,color_FFFFFF,t_70#pic_center)
（1） 某个应用进程首先调用close，称该端执行“主动关闭”（active close）。该端的TCP于是发送一个FIN分节，表示数据发送完毕。

（2） 接收到这个FIN的对端执行 “被动关闭”（passive close），这个FIN由TCP确认。

注意：FIN的接收也作为一个文件结束符（end-of-file）传递给接收端应用进程，放在已排队等候该应用进程接收的任何其他数据之后，因为，FIN的接收意味着接收端应用进程在相应连接上再无额外数据可接收。

（3） **一段时间后**，接收到这个文件结束符的应用进程将调用close关闭它的套接字。这导致它的TCP也发送一个FIN。

（4） 接收这个最终FIN的原发送端TCP（即执行主动关闭的那一端）确认这个FIN。既然每个方向都需要一个FIN和一个ACK，因此通常需要4个分节。
![四次挥手](https://img-blog.csdnimg.cn/20200411104000955.gif#pic_center)
**注意：**

（1）“通常”是指，某些情况下，步骤1的FIN随数据一起发送，另外，步骤2和步骤3发送的分节都出自执行被动关闭那一端，有可能被合并成一个分节。

（2）在步骤2与步骤3之间，从执行被动关闭一端到执行主动关闭一端流动数据是可能的，这称为“半关闭”（half-close）。

（3）当一个Unix进程无论自愿地（调用exit或从main函数返回）还是非自愿地（收到一个终止本进程的信号）终止时，所有打开的描述符都被关闭，这也导致仍然打开的任何TCP连接上也发出一个FIN。

&emsp;无论是客户还是服务器，任何一端都可以执行主动关闭。通常情况是，客户执行主动关闭，但是某些协议，例如，HTTP/1.0却由服务器执行主动关闭。

**六. 为什么要三次握手和四次挥手？**
&emsp;**1.为什么要三次握手？两次可以吗？**
&emsp;**目的：为了防止已失效的连接请求报文段突然又传送到了服务端，因而产生错误。主要防止资源的浪费。**
**&emsp;具体过程：**
&emsp;当客户端发出第一个连接请求报文段时并没有丢失，而是在某个网络节点出现了长时间的滞留，以至于延误了连接请求在某个时间之后才到达服务器。这应该是一个**早已失效的报文段**。但是服务器在收到此**失效的连接请求报文段**后，以为是客户端的一个新请求，于是就向客户端发出了确认报文段，同意建立连接。**假设不采用三次握手，而是两次**，那么只要服务器发出确认后，新的连接就可以建立了。但是由于客户端没有发出建立连接的请求，因此不会管服务器的确认，也不会向服务器发送数据，但服务器却以为新的运输连接已经建立，一直在等待，所以，服务器的资源就白白浪费掉了。

&emsp;**2.如果在TCP第三次握手中的报文段丢失了会出现什么情况？**

&emsp;客户端会认为此连接已建立，如果客户端向服务器发送数据，服务器将以RST包响应，这样就能感知到服务器的错误了。

&emsp;**3.为什么要四次挥手？**
**&emsp;目的：为了保证在最后断开的时候，主动方能够发送最后一个ACK报文段能够被被动方接收到。**

**&emsp;反过来说：防止已经失效的连接请求报文突然又传送到了服务器，从而产生错误。**

&emsp;如果被动方在收到主动方给它的断开连接的请求之后，回应完主动方就直接断开连接的话，若主动方没有收到回应就无法进入CLOSE状态，所以被动方要等待**两个最长报文段寿命的时间（2MSL）**，以便于主动方没有收到请求之后重新发送请求。

&emsp;防止“已失效的连接请求报文”出现在连接中，在释放连接的过程中会有一些无效的滞留报文，这些报文在经过2MSL的时间内就可以发送到目的地，不会滞留在网络中。这样就可以避免在下一个连接中出现上一个连接的滞留报文了。

&emsp;当被动方收到主动方的FIN报文通知时，它仅仅表示主动方没有数据再发送给被动方了。但未必被动方所有的数据都完整的发送给了主动方，所以被动方不会马上断开连接，它可能还需要发送一些数据给主动方后，再发送FIN报文给主动方，告诉主动方同意关闭连接，所以这里的ACK报文和FIN报文多数情况下都是分开发送的。

**七. 常见问题**
**&emsp;1.描述一下或者画一下三次握手过程。
&emsp;2.描述一下或者画一下四次握手过程。
&emsp;3.为什么建立连接是三次握手？两次可以吗？四次可以吗？（口述版打比方，A，B连接，如果是两次会怎么样，如果是三次会怎么样，如果是四次会怎么样）**
&emsp; **答：** 两次不可以，四次可以，但是没有必要。

&emsp;**这主要是为了防止已失效的请求连接报文忽然又传送到了，从而产生错误。**

&emsp;**思路一：** 假定A向B发送一个连接请求，由于一些原因，导致A发出的连接请求在一个网络节点逗留了比较多的时间。此时A会将此连接请求作为无效处理又重新向B发起了一次新的连接请求，B正常收到此连接请求后建立了连接，数据传输完成后释放了连接。如果此时A发出的第一次请求又到达了B，B会以为A又发起了一次连接请求，如果是两次握手：此时连接就建立了，B会一直等待A发送数据，从而白白浪费B的资源。如果是三次握手：由于A没有发起连接请求，也就不会理会B的连接响应，B没有收到A的确认连接，就会关闭掉本次连接。

**&emsp;思路二：**

**&emsp;第一次握手：**
&emsp;Client什么都确认不了，Server确认了对方发送正常。

**&emsp;第二次握手：**

&emsp;Client确认：自己发送/接收正常，对方发送/接收正常；

&emsp;Server确认：自己接收正常 ，对方发送正常。

**&emsp;第三次握手：**

&emsp;Client确认：自己发送/接收正常，对方发送/接收正常；

&emsp;Server确认：自己发送/接收正常 ，对方发送/接收正常。

**&emsp;所以通过三次握手确认双方收发功能都正常，四次也可以但是显得比较多余。**

**&emsp;4.为什么建立连接是三次握手，断开连接却是四次挥手呢？（分成两个方面回答）**

&emsp;答：**建立连接的时候**， 服务器在LISTEN状态下，收到建立连接请求的SYN报文后，把ACK和SYN放在一个报文里发送给客户端。 

&emsp;**而断开连接的时候**，服务器收到对方的FIN报文时，仅仅表示对方不再发送数据了但是还能接收数据，而自己也未必全部数据都发送给对方了，所以己方可以立即关闭，也可以发送一些数据给对方后，再发送FIN报文给对方来表示同意现在关闭连接，因此，己方ACK和FIN一般都会分开发送，从而导致多了一次。

**&emsp;5.如果已经建立了连接，但是客户端突然出现故障了怎么办？**

&emsp;**答：** TCP还设有一个保活计时器，显然，客户端如果出现故障，服务器不能一直等下去，白白浪费资源。服务器每收到一次客户端的请求后都会重新复位这个计时器，时间通常是设置为2小时，若两小时还没有收到客户端的任何数据，服务器就会发送一个探测报文段，以后每隔75分钟发送一次。若一连发送10个探测报文仍然没反应，服务器就认为客户端出了故障，接着就关闭连接。

**&emsp;6.为什么客户端最后还要等待2MSL？（为什么需要TIME_WAIT状态？）**

&emsp;**答：最长报文段寿命的时间（Maximum Segment Lifetime，MSL）**，TCP允许不同的实现可以设置不同的MSL值。

&emsp;**第一**，保证客户端发送的最后一个ACK报文能够到达服务器，因为这个ACK报文可能丢失，站在服务器的角度看来，我已经发送了FIN+ACK报文请求断开了，客户端还没有给我回应，应该是我发送的请求断开报文它没有收到，于是服务器又会重新发送一次，而客户端就能在这个2MSL时间段内收到这个重传的报文，接着给出回应报文，并且会重启2MSL计时器。

&emsp;**第二**，防止类似与“三次握手”中提到了的“已经失效的连接请求报文段”出现在本连接中。客户端发送完最后一个确认报文后，在这个2MSL时间中，就可以使本连接持续的时间内所产生的所有报文段都从网络中消失。这样新的连接中不会出现旧连接的请求报文。

**&emsp;7.描述一下超时重传和快速重传技术。**

**&emsp;答：**

&emsp;**超时重传**：当超时时间到达时，发送方还未收到对端的ACK确认，就重传该数据包。

&emsp;**快速重传**：当后面的序号先到达，如接收方接收到了1、 3、 4，而2没有收到，就会立即向发送方重复发送三次ACK=2的确认请求重传。如果发送方连续收到3个相同序号的ACK，就重传该数据包。而不用等待超时。

**&emsp;8.第三次握手可以携带数据吗？为什么？**

&emsp;**答**：可以，能够发出第三次握手报文的客户端，一定接收到了第二次握手的报文，因为伪造IP的主机是不会收到第二次报文的。所以能够发出第三次握手报文的客户端是合法的客户端。尽管服务器端的状态还没有切换为“established”，接收到第三次握手报文的瞬间，状态就会切换为“established”，报文中携带的数据按照正常的流程继续进行就可以了。

**&emsp;9.TCP和UDP的区别：**

**&emsp;答：**

&emsp;TCP是**有连接的**，两台主机在进行数据交互之前必须先通过三次握手建立连接；而UDP是无连接的，没有建立连接这个过程。

&emsp;TCP是**可靠的传输**，TCP协议通过确认和重传机制来保证数据传输的可靠性；而UDP是不可靠的传输。

&emsp;TCP还提供了**拥塞控制、滑动窗口**等机制来保证传输的质量，而UDP都没有。

&emsp;TCP是**基于字节流**的，将数据看做无结构的字节流进行传输，当应用程序交给TCP的数据长度太长，超过MSS时，TCP就会对数据进行分段，因此TCP的数据是无边界的；而UDP是**面向报文的**，无论应用程序交给UDP层多长的报文，UDP都不会对数据报进行任何拆分等处理，因此**UDP保留了应用层数据的边界** 。

**&emsp;10.SYN Flood攻击（DOS攻击的一种）原理：**

&emsp;**答**：TCP连接的三次握手中，假设一个用户向服务器发送了SYN报文后突然死机或掉线，那么服务器在发出SYN+ACK应答报文后是无法收到客户端的ACK报文的(第三次握手无法完成)，这种情况下服务器端一般会重试(再次发送SYN+ACK给客户端)并等待一段时间后丢弃这个未完成的连接。这段时间的长度我们称为SYN Timeout，一般来说这个时间是分钟的数量级(大约为30秒~2分钟)；一个用户出现异常导致服务器的一个线程等待1分钟并不是什么很大的问题，但如果有一个恶意的攻击者大量模拟这种情况(伪造IP地址)，服务器端将为了维护一个非常大的半连接列表而消耗非常多的资源。即使是简单的保存并遍历也会消耗非常多的CPU时间和内存，何况还要不断对这个列表中的IP进行SYN+ACK的重试。实际上如果服务器的TCP/IP栈不够强大，最后的结果往往是堆栈溢出崩溃—— 即使服务器端的系统足够强大，服务器端也将忙于处理攻击者伪造的TCP连接请求而无暇理睬客户的正常请求(毕竟客户端的正常请求比率非常之小)，此时从正常客户的角度看来，服务器失去响应，这种情况就称作：服务器端受到了SYN Flood攻击(SYN洪水攻击)。

&emsp;**防范措施**：①降低SYN timeout时间，使得主机尽快释放半连接的占用。②采用SYN cookie设置，如果短时间内连续收到某个IP的重复SYN请求，则认为受到了该IP的攻击，丢弃来自该IP的后续请求报文。③在网关处设置过滤，拒绝将一个源IP地址不属于其来源子网的包进行更远的路由。

**&emsp;11.有哪些应用层协议是基于TCP的，哪些是基于UDP的：**

**&emsp;答：**

- TCP：FTP、HTTP、Telnet、SMTP、POP3、HTTPS

- UDP：DNS、SNMP、NFS

**&emsp;12.简述一下滑动窗口协议，它有什么意义？**

&emsp;**答**：**首先明确：TCP滑动窗口分为接收窗口，发送窗口。**

&emsp;滑动窗口协议是传输层进行流控的一种措施，接收方通过通告发送方自己的窗口大小，从而控制发送方的发送速度，从而达到防止发送方发送速度过快而导致自己被淹没的目的。
&emsp;对ACK的再认识，ack通常被理解为收到数据后给出的一个确认ACK，ACK包含两个非常重要的信息：
&emsp;一是期望接收到的下一字节的序号n，该n代表接收方已经接收到了前n-1字节数据，此时如果接收方收到第n+1字节数据而不是第n字节数据，接收方是不会发送序号为n+2的ACK的。举个例子，假如接收端收到1-1024字节，它会发送一个确认号为1025的ACK,但是接下来收到的是2049-3072，它是不会发送确认号为3072的ACK,而依旧发送1025的ACK。
&emsp;二是当前的窗口大小m，如此发送方在接收到ACK包含的这两个数据后就可以计算出还可以发送多少字节的数据给对方，假定当前发送方已发送到第x字节，则可以发送的字节数就是y=m-(x-n).这就是滑动窗口控制流量的基本原理。

**&emsp;重点：发送方根据收到ACK当中的期望收到的下一个字节的序号n以及窗口m，还有当前已经发送的字节序号x，算出还可以发送的字节数。**
&emsp;发送端窗口的第一个字节序号一定是ACK中期望收到的下一个字节序号，比如下图：
![](https://img-blog.csdnimg.cn/20200411104212971.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0dvbmdfWWloYW5n,size_16,color_FFFFFF,t_70#pic_center)
&emsp;上图52 53 54 55 字节都是可以新发送的字节序
&emsp;接受端窗口的第一个字节序之前一定是已经完全接收的，后面窗口里面的数据都是希望接受的，窗口后面的数据都是不希望接受的。

**&emsp;TCP的滑动窗口分为接收窗口和发送窗口，不分析这两种窗口就讨论是不妥当的。**
**&emsp;TCP的滑动窗口主要有两个作用：一是提供TCP的可靠性；二是提供TCP的流控特性。** 同时滑动窗口机制还体现了TCP面向字节流的设计思路。TCP 段中窗口的相关字段。
![](https://img-blog.csdnimg.cn/20200411104244409.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0dvbmdfWWloYW5n,size_16,color_FFFFFF,t_70#pic_center)
&emsp;TCP的Window是一个16bit位字段，它代表的是窗口的字节容量，也就是TCP的标准窗口最大为2^16-1=65535个字节。

&emsp;另外在TCP的选项字段中还包含了一个TCP窗口扩大因子，option-kind为3，option-length为3个字节，option-data取值范围0-14。窗口扩大因子用来扩大TCP窗口，可把原来16bit的窗口，扩大为31bit。

**&emsp;滑动窗口基本原理：**

&emsp;1）对于TCP会话的发送方，任何时候在其发送缓存内的数据都可以分为4类，“已经发送并得到对端ACK的”，“已经发送但还未收到对端ACK的”，“未发送但对端允许发送的”，“未发送且对端不允许发送”。“已经发送但还未收到对端ACK的”和“未发送但对端允许发送的”这两部分数据称之为发送窗口。
![](https://img-blog.csdnimg.cn/20200411104309878.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0dvbmdfWWloYW5n,size_16,color_FFFFFF,t_70#pic_center)
&emsp;当收到接收方新的ACK对于发送窗口中后续字节的确认时，窗口滑动，滑动原理如下图。
![](https://img-blog.csdnimg.cn/20200411104346766.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0dvbmdfWWloYW5n,size_16,color_FFFFFF,t_70#pic_center)
&emsp;当收到ACK=36时窗口滑动。

&emsp;2）对于TCP的接收方，在某一时刻在它的接收缓存内存在3种。“已接收”，“未接收准备接收”，“未接收并未准备接收”（由于ACK直接由TCP协议栈回复，默认无应用延迟，不存在“已接收未回复ACK”）。其中“未接收准备接收”称之为接收窗口。

**&emsp;发送窗口与接收窗口关系：**

&emsp;TCP是全双工的协议，会话的双方都可以同时接收、发送数据。TCP会话的双方都各自维护一个“发送窗口”和一个“接收窗口”。其中各自的“接收窗口”大小取决于应用、系统、硬件的限制（TCP传输速率不能大于应用的数据处理速率）。各自的“发送窗口”则要求取决于对端通告的“接收窗口”，要求相同。
![](https://img-blog.csdnimg.cn/20200411104409462.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0dvbmdfWWloYW5n,size_16,color_FFFFFF,t_70#pic_center)
**&emsp;滑动窗口实现面向流的可靠性：**

&emsp;1）最基本的传输可靠性来源于“确认重传”机制。

&emsp;2）TCP的滑动窗口的可靠性也是建立在“确认重传”基础上的。

&emsp;3）发送窗口只有收到对端对于本段发送窗口内字节的ACK确认，才会移动发送窗口的左边界。

&emsp;4）接收窗口只有在前面所有的段都确认的情况下才会移动左边界。当在前面还有字节未接收但收到后面字节的情况下，窗口不会移动，并不对后续字节确认。以此确保对端会对这些数据重传。

**&emsp;滑动窗口的流控特性：**

&emsp;TCP的滑动窗口是动态的，我们可以想象成小学常见的一个数学题，一个水池，体积V，每小时进水量V1，出水量V2。当水池满了就不允许再注入了，如果有个液压系统控制水池大小，那么就可以控制水的注入速率和量。这样的水池就类似TCP的窗口。应用根据自身的处理能力变化，通过本端TCP接收窗口大小控制来对对对端的发送窗口流量限制。

&emsp;应用程序在需要（如内存不足）时，通过API通知TCP协议栈缩小TCP的接收窗口。然后TCP协议栈在下个段发送时包含新的窗口大小通知给对端，对端按通知的窗口来改变发送窗口，以此达到减缓发送速率的目的。
![公众号：一航代码](https://img-blog.csdnimg.cn/20200411104731739.jpg?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0dvbmdfWWloYW5n,size_16,color_FFFFFF,t_70#pic_center)  

