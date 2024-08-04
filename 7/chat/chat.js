//<!-- WebSocketのクライアントの生成 （※ localhost ～ マシン内で確認） -->
let ws = new WebSocket('ws://localhost:8080');

//<!-- 接続時に実行 ～ openイベントが発生 -->
ws.addEventListener('open', e => { 
    console.log('WebSocket で接続'); 
});

//<!-- サーバからデータ受信 ～ messageイベント発生、e.dataとして格納データをコンソール表示 -->
ws.addEventListener('message', e => { 
    //console.log(e.target);
    const receivedata = JSON.parse(e.data);

    console.log(receivedata); 

    displayUser(receivedata.user, receivedata.from);
    displayMessage(receivedata.message, receivedata.from);
});


//wsを使って送信
document.getElementById('message_button').addEventListener('click', e =>{
    var user = document.input2.user.value;
    var message = document.input2.message.value;
    if(user && message){
        const data = JSON.stringify({user: user, message: message});
        ws.send(data);
        document.input2.message.value = '';
    }
});

//ユーザー表示
function displayUser(user, type){
    let ChatArea = document.getElementById('chat_area');
    let MessageElement = document.createElement('div');
    if(type == 'myself'){
        MessageElement.textContent = 'あなた';
        MessageElement.classList.add('user_myself');
        ChatArea.appendChild(MessageElement);
    } else{
        MessageElement.textContent = user;
        MessageElement.classList.add('user_other');
        ChatArea.appendChild(MessageElement);
    }
} 

//メッセージを表示
function displayMessage(message, type){
    let ChatArea = document.getElementById('chat_area');
    let MessageElement = document.createElement('div');
    if(type == 'myself'){
        MessageElement.classList.add('message_myself');
        MessageElement.textContent = message;
        ChatArea.appendChild(MessageElement);
    } else {
        MessageElement.classList.add('message_other');
        MessageElement.textContent = message;
        ChatArea.appendChild(MessageElement);
    }
}