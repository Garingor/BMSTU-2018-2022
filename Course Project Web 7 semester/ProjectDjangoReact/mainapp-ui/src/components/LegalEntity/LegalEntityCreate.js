import React, { useState } from "react";
import 'bootstrap/dist/css/bootstrap.min.css';

function LegalEntityCreate() {
  const [name, setName] = useState("");
  const [surname, setSurname] = useState("");
  const [patronymic, setPatronymic] = useState("");
  const [address, setAddress] = useState("");
  const [inn, setInn] = useState("");
  const [seriespassport, setSeriesPassport] = useState("");
  const [numberpassport, setNumberPassport] = useState("");
  const [employeenumber, setEmployeeNumber] = useState("");

  const handleSubmit = (e) => {
    e.preventDefault();
    const legalentity = { name, surname, patronymic, address, inn, seriespassport, numberpassport, employeenumber };

    fetch('http://127.0.0.1:8000/api/v1/legalentities/', {
      method: 'POST',
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify(legalentity)
    }).then(() => {
      console.log('new legal entity added');
    })
  }

  return (
    <div className="row">
            <div className="col-md-12">
                <div className="card card-body">
                    <h5>Добавить новое юридическое лицо:</h5>
                        <br/>
                            <div>
                              <form onSubmit={handleSubmit}>
                                <label>Имя:</label>
                                <input
                                  type="text"
                                  required
                                  value={name}
                                  onChange={(e) => setName(e.target.value)}
                                /> <br /><br />

                                <label>Фамилия:</label>
                                <input
                                  type="text"
                                  required
                                  value={surname}
                                  onChange={(e) => setSurname(e.target.value)}
                                /> <br /><br />

                                <label>Отчество:</label>
                                <input
                                  type="number"
                                  required
                                  value={patronymic}
                                  onChange={(e) => setPatronymic(e.target.value)}
                                /> <br /><br />

                                <label>Адрес:</label>
                                <input
                                  type="text"
                                  required
                                  value={address}
                                  onChange={(e) => setAddress(e.target.value)}
                                /> <br /><br />

                                <label>ИНН:</label>
                                <input
                                  type="number"
                                  required
                                  value={inn}
                                  onChange={(e) => setInn(e.target.value)}
                                /> <br /><br />

                                <label>Серия паспорта:</label>
                                <input
                                  type="number"
                                  required
                                  value={seriespassport}
                                  onChange={(e) => setSeriesPassport(e.target.value)}
                                /> <br /><br />

                                <label>Номер паспорта:</label>
                                <input
                                  type="number"
                                  required
                                  value={numberpassport}
                                  onChange={(e) => setNumberPassport(e.target.value)}
                                /> <br /><br />

                                <label>Кол-во подчиненных:</label>
                                <input
                                  type="text"
                                  required
                                  value={employeenumber}
                                  onChange={(e) => setEmployeeNumber(e.target.value)}
                                /> <br /><br />

                                <button className="btn btn-sm btn-outline-info">Добавить юридическое лицо</button>
                              </form>
                            </div>
                </div>
            </div>
    </div>
  );

}

export default LegalEntityCreate;