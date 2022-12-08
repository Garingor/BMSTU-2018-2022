import './App.css';
import 'bootstrap/dist/css/bootstrap.min.css'

import Navbar from "./components/Navigation/Navbar"

import RoomList from "./components/Room/RoomList";
import RoomUpdate from "./components/Room/RoomUpdate";
import RoomCreate from "./components/Room/RoomCreate";

import ObjectList from "./components/Object/ObjectList";
import ObjectUpdate from "./components/Object/ObjectUpdate";
import ObjectCreate from "./components/Object/ObjectCreate";

import LegalEntityList from "./components/LegalEntity/LegalEntityList";
import LegalEntityUpdate from "./components/LegalEntity/LegalEntityUpdate";
import LegalEntityCreate from "./components/LegalEntity/LegalEntityCreate";

import EmployeeList from "./components/Employee/EmployeeList";
import EmployeeUpdate from "./components/Employee/EmployeeUpdate";
import EmployeeCreate from "./components/Employee/EmployeeCreate";

import Home from "./components/Account/Home";
import Login from "./components/Account/Login";
import SignUp from "./components/Account/Signup";
import Activate from "./components/Account/Activate";
import ResetPassword from "./components/Account/ResetPassword";
import ResetPasswordConfirm from "./components/Account/ResetPasswordConfirm";

import Layout from "./hocs/Layout";

import { Provider } from "react-redux";
import store from "./store";

import { BrowserRouter as Router, Route, Routes } from 'react-router-dom'

function App() {

  return (
    <div className="App">
        <Provider store={store}>
            <Router>
                <Layout>

                    <Routes>
                        <Route path="/" exact element={<Home/>} />
                        <Route path="/login" exact element={<Login/>} />
                        <Route path="/signup" exact element={<SignUp/>} />
                        <Route path="/reset-password" exact element={<ResetPassword/>} />
                        <Route path="/password/reset/confirm/:uid/:token" exact element={<ResetPasswordConfirm/>} />
                        <Route path="/activate/:uid/:token" exact element={<Activate/>} />

                        <Route path="/rooms" exact element={<RoomList/>} />
                        <Route path="/rooms/edit/:id" exact element={<RoomUpdate/>} />
                        <Route path="/rooms/add" exact element={<RoomCreate/>} />

                        <Route path="/objects" exact element={<ObjectList/>} />
                        <Route path="/objects/edit/:id" exact element={<ObjectUpdate/>} />
                        <Route path="/objects/add" exact element={<ObjectCreate/>} />

                        <Route path="/legalentities" exact element={<LegalEntityList/>} />
                        <Route path="/legalentities/edit/:id" exact element={<LegalEntityUpdate/>} />
                        <Route path="/legalentities/add" exact element={<LegalEntityCreate/>} />

                        <Route path="/employees" exact element={<EmployeeList/>} />
                        <Route path="/employees/edit/:id" exact element={<EmployeeUpdate/>} />
                        <Route path="/employees/add" exact element={<EmployeeCreate/>} />
                    </Routes>
                </Layout>
            </Router>
        </Provider>
    </div>
  );
}

export default App;
