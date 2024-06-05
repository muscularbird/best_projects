import image from '../../Assets/404-Error.png'
import '../../Styles/error.css'

function Error() {
    return(
        <div>
            <img src={image} alt="404" className='error'/>
            <h3 style={{textAlign: 'center'}}>Il semblerait qu'il y ai une erreur</h3>
        </div>
    )
}

export default Error