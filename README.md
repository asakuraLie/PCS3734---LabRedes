# PCS3734 Laboratório de Redes de Computadores

# Setup

- Tenha certeza de que o Node está instalado: https://nodejs.org/en/blog/release/v19.5.0
- Documentação: https://docs.expo.dev/

`npm install`

`npx expo install react-dom react-native-web @expo/webpack-config`

`npm install expo-font axios react-native-dotenv`

`npx expo install expo-font@~11.1.1 react-native@0.71.8`

`npm install @react-navigation/native`

`npm install react-native-screens react-native-safe-area-context`

`https://blog.logrocket.com/using-react-native-ble-manager-mobile-app/`

Para testar a aplicação:

- Baixe o aplicativo: Expo Go
- Rode `npm start` na pasta react-native-redes
- Escaneie o QR Code dentro do aplicativo

Caso os passos de cima não funcionem:

- Rode o seguinte comando: `npm install -g expo-cli`
- Dentro da pasta react-native-redes, compile o projeto com `expo-cli start --tunnel`
- Escaneie novamente o QR Code dentro do aplicativo

# Explicaçõezinhas Gerais

Para este projeto, vamos estar utilizando o Expo para React Native, que funciona igual ao react-create-web-app facilitando as navegações nas telas do aplicativo. Na parte da programação, vamos usar o JavaScript como no próprio React e os nossos componentes vão ser da seguinte forma:

```
import React from 'react';
import {View, Text} from 'react native';

const App = () => {
    return(
        <View>
            <Text>Hello World!</Text>
        </View>)
}
```

Ou para o caso de botões temos:

```
import React from 'react';
import { TouchableOpacity, Text } from 'react-native';

function MyButton(props) {
    return (
        <TouchableOpacity onPress={props.onPress}>
            <Text>{props.label}</Text>
        </TouchableOpacity>
    );
}
```

O Text irá substituir o `<h1>`, `<p1>` etc do JavaScript. Já o View serve para criar containers ou "view" para outros componentes. Pensem como uma caixa que comporta outros componentes, tipo uma `<div>` com mais funcionalidades.
