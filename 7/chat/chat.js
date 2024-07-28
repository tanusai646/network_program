//<!-- WebSocketのクライアントの生成 （※ localhost ～ マシン内で確認） -->
let ws = new WebSocket('ws://localhost:8080');

//<!-- 接続時に実行 ～ openイベントが発生 -->
ws.addEventListener('open', e => { 
    console.log('WebSocket で接続'); 
});

//<!-- サーバからデータ受信 ～ messageイベント発生、e.dataとして格納データをコンソール表示 -->
ws.addEventListener('message', e => { 
    console.log(e.data); 
    displayMessage(e.data);
});

//<!-- ボタンクリック時に実行 ～ my_messageに送信したい文字列を設定し、WSサーバへ送信 -->
document.getElementById('send_button').addEventListener('click', e => {
    var my_message = "hello";
    ws.send(my_message);
});

//コンソールに送信
document.getElementById('message_button').addEventListener('click', e =>{
    var user = document.input2.user.value;
    var message = document.input2.message.value;
    if(user && message){
        const data = {user: user, message: message};
        ws.send(my_put_message);
        document.input2.message.value = '';
    }
});

//メッセージを表示
function displayMessage(message){
    let ChatArea = document.getElementById('chat_area');
    let MessageElement = document.createElement('div')
    MessageElement.textContent = message;
    ChatArea.appendChild(MessageElement);
}