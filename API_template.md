#### 书写规范
* Markdown的缩进为2个空格
* 代码缩进不限制
#### 动态页 (屏幕底部tab名称)
* 获取动态 (页面内功能)
  * 请求函数
    * ???
  * 请求模式
    * GET 
  * 请求触发时机
    * 页面在初始化时
    * 页面滑动至底端时加载新页面 
  * 请求json
  ```javascript
    { 
      'uid': String,            // 用户名
      'uim': String,            // 用户头像的路径
      'uuni': String,           // 用户学校
      'type': String,           // 动态类型，例如“想法”
      'utype': int,             // 动态辨识符，例如**1**表示**辩论邀约，**其余数字表示想法
      'payment': int,           // 悬赏金
      'time': String,           // 时间，例如 “17小时前”、“2天前”. 前端处理可能会涉及读取用户的时间状态，比较麻烦，麻烦后端的同学直接传回可以显示的字符串
      'description': String,    // 描述, 这是动态评论框的 placeholder，其具体作用还需要向设计者询问一下
      'content': {              // 内容
        'title': String,        // 标题
        'time': String,         // 发布时间,只有辩论邀约有这一项，倘若为想法动态，可以传入任意的字符串 
        'place': String,        // 地点 只有辩论邀约有这一项，倘若为想法动态，可以传入任意的字符串
        'snapShot': String,     // 动态内容
        'type': String,         // 动态 是否有图片有图片为**1**，其他数字表示没有图片
        'im': String            // 图片路径同理，没有图片呢传入任意字符串
      }
    }
  ```
* 发布动态 (页面内功能)
  * 请求函数
    * getMomentByUser(String JWToken, int Offset)
    * JWToken是为用户的???
    * Offset是表示当前动态的个数
  * 请求模式  
    * POST  
  * 请求触发时机
    * 
  * 响应json  
  ```javascript
  {
    invitationList:[
      {
        uid:"Rvan Raj",
        uim:"/images/icon/用户头像.png",
        uuniv:"复旦大学",
        utype:"辩论邀约",
        uutype:1,
        content:{
          title:"#辩论赛招募 | 演讲与口才协会 x 生命自然协会 #",
          time: "2020年10月5日",
          place:"复旦大学报告厅",
          snapShot:"回收，空调，洗衣机，冰箱，彩电，旧手表，旧手机，旧空调，旧电脑~回收，空调，洗衣机，冰箱，彩电，旧手表，旧手机，旧空调，旧电脑~回收，空调，洗衣机，冰箱，彩电，旧手表，旧手机，旧空调，旧电脑~回收，空调，洗衣机，冰箱，彩电，旧手表，旧手机，旧空调，旧电脑~",
          type:1,
          im:"/images/icon/复旦大学学术报告厅.png"
        },
        payment: 10,
        time:"17小时前",
        description:"辩手们，快来参加吧！",
      }
    ]
  }
  ```  
