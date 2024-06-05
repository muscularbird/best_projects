import DefaultPicture from '../../Assets/images.jpeg'
import Card from '../../components/Card'
import styled from 'styled-components'
import { useEffect, useState } from 'react'
import { Loader } from '../../utils/style/Atoms'
import { ThemeContext } from '../../utils/context'
import { useContext } from "react";

const CardContainer = styled.div`
    display: grid;
    gap: 24px;
    grid-template-rows: 350px 350px;
    grid-template-columns: repeat(2, 1fr);
    align-items: center;
    justify-items: center;
`

const StyledTitle = styled.h3`
    text-align: center;`

const CenterLoader = styled.div`
    margin-top: 50px;
    display: flex;
    justify-content: center;
    align-items: center;
`

function Freelances() {
    const [isDataLoading, setDataLoading] = useState(false)
    const [error, setError] = useState(false)
    const [freelancersList, setfreelancersList] = useState([])
    const { toggletheme, theme} = useContext(ThemeContext)

    useEffect(() => {
        async function fetchFreelances() {
            setDataLoading(true)
            try {
                const response = await fetch(`http://localhost:8000/freelances`)
                const { freelancersList } = await response.json()
                setfreelancersList(freelancersList)
            } catch(err) {
                console.log(' errrrror')
                setError(true)
            } finally {
                setDataLoading(false)
            }
        }
        fetchFreelances()
    }, [])

    if (error) {
        return <span>Il y a eu un problème  de connection à l'API</span>
    }
    return (
        <div>
            <h2 style={{'textAlign': 'center'}}>Trouvez votre prestataire</h2>
            <StyledTitle>Chez Shiny nous réunissons les meilleurs profils pour vous</StyledTitle>
            {isDataLoading ? (
                <CenterLoader><Loader /></CenterLoader>
            ) : (
                <CardContainer>
                    {freelancersList.map((profile, index) => (
                        <Card isDarkMode={theme === 'dark'}
                            key={`${profile.name}-${index}`}
                            label={profile.job}
                            title={profile.name}
                            picture={profile.picture}
                        />
                    ))}
                </CardContainer>
            )}
        </div>
    )
}

export default Freelances