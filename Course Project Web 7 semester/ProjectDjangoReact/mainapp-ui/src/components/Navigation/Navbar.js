import 'bootstrap/dist/css/bootstrap.min.css';
import React, { Fragment } from 'react';
import { Link } from 'react-router-dom'
import logo from './logo_dj.png';
import { connect } from 'react-redux';
import { logout } from '../../actions/auth';

function Navbar( { logout, isAuthenticated } ) {

  const guestLinks = () => (
        <Fragment>
            <li className='nav-item'>
                <Link className='nav-link' to='/login'>Авторизация</Link>
            </li>
            <li className='nav-item'>
                <Link className='nav-link' to='/signup'>Регистрация</Link>
            </li>
        </Fragment>
    );

  const authLinks = () => (

      <Fragment>
        <li className="nav-item">
            <Link className="nav-link" to={{pathname: `/legalentities/`, fromDashboard: false}}>Юридические лица</Link>
        </li>

        <li className='nav-item'>
            <Link className="nav-link" to={{pathname: `/employees/`, fromDashboard: false}}>Сотрудники</Link>
        </li>

        <li className='nav-item'>
            <Link className="nav-link" to={{pathname: `/objects/`, fromDashboard: false}}>Оборудование</Link>
        </li>

        <li className='nav-item'>
            <Link className="nav-link" to={{pathname: `/rooms/`, fromDashboard: false}}>Помещения</Link>
        </li>

        <li className='nav-item'>
            <div>{  }</div>
        </li>
        <li className='nav-item'>
            <a className='nav-link' href='#!' onClick={logout}>Выйти</a>
        </li>
      </Fragment>
    );

  return (
    <div className="App">
        <nav className="navbar navbar-expand-lg navbar-dark bg-dark">
            <img src={logo} alt="Logo" />
            <button className="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarNav"
                    aria-controls="navbarNav" aria-expanded="false" aria-label="Toggle navigation">
                <span className="navbar-toggler-icon"></span>
            </button>
            <div className="collapse navbar-collapse" id="navbarNav">
                <ul className="navbar-nav">
                    <li className="nav-item">
                        <Link className="nav-link" to={{pathname: `/`, fromDashboard: false}}>Начальная страница</Link>
                    </li>
                    {isAuthenticated ? authLinks() : guestLinks()}
                </ul>
            </div>
        </nav>
    </div>
  );
}

const mapStateToProps = state => ({
    isAuthenticated: state.auth.isAuthenticated
});

export default connect(mapStateToProps, { logout })(Navbar);