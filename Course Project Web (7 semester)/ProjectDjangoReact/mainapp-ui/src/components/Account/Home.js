import React from 'react';
import { Link } from 'react-router-dom';

const Home = () => (
    <div className='container'>
        <div class='jumbotron mt-5'>
            <h1 class='display-4'>Добро пожаловать в систему инвентаризации!</h1>
            <hr class='my-4' />
            <Link class='btn btn-primary btn-lg' to='/login' role='button'>Войти</Link>
        </div>
    </div>
);

export default Home;